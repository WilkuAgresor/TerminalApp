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
    qDebug() << "parsed message: "<< msg.toString();

    auto messageType = msg.getHeader().getType();

    if(isHeatingMessage(messageType))
    {
        mComponents.getHeatingApp().handleMessage(msg);
    }
    else if(messageType == MessageType::TOPOLOGY_REQUEST_CHECKIN)
    {
        {
            qDebug() << "replying to checkin request";
            TopologyCheckInMessage message;
            mComponents.getSender().send(mDatagram.senderAddress(), 2222, message.toData());
        }
        if(mComponents.getDataInitPhase() == DataInitPhase::UNINITIALIZED)
        {
            qDebug() << "requesting data initiation from master node";
            TopologyRequestInitMessage initMessage;
            mComponents.getSender().send(mDatagram.senderAddress(), 2222, initMessage.toData());
            mComponents.setDataInitPhase(DataInitPhase::READY);
        }
    }
}
