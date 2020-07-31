#include <MessageHandler.hpp>
#include <../common/subsystems/alarm/alarmSetMessage.hpp>
#include <../common/messages/replyMessage.hpp>
#include <../common/subsystems/topology/topologyMessages.hpp>

#include <chrono>
#include <thread>

MessageHandler::MessageHandler(QNetworkDatagram datagram, Components& components)
    : mDatagram(datagram), mComponents(components)
{
}

void MessageHandler::run()
{
    Message msg(mDatagram.data());
//    qDebug() << "parsed message: "<< msg.toString();
    auto header = msg.getHeader();

    auto messageType = header.getType();

    if(isHeatingMessage(messageType))
    {
        mComponents.getHeatingApp().handleMessage(msg, mDatagram.senderAddress(), mDatagram.senderPort());
    }
    else if(isLightsMessage(messageType))
    {
        mComponents.getLightsApp().handleMessage(msg, mDatagram.senderAddress(), mDatagram.senderPort());
    }
    else if(messageType == MessageType::TOPOLOGY_REQUEST_CHECKIN)
    {
        {
            TopologyCheckInMessage message;

            if(mDatagram.senderAddress() != mComponents.getMasterAddress())
            {
                mComponents.setMasterAddress(mDatagram.senderAddress());
            }

            if(header.mReplyPort != mComponents.getMasterPort())
            {
                mComponents.setMasterPort(header.mReplyPort);
            }

            mComponents.getSender().send(mComponents.getMasterAddress(), mComponents.getMasterPort(), message.toData());
        }
        if(mComponents.getDataInitPhase() == DataInitPhase::UNINITIALIZED)
        {
            TopologyRequestInitMessage initMessage;
            mComponents.getSender().send(mComponents.getMasterAddress(), mComponents.getMasterPort(), initMessage.toData());
            mComponents.setDataInitPhase(DataInitPhase::READY);
        }
    }
}
