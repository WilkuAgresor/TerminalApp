#include <MessageHandler.hpp>
#include <../common/subsystems/alarm/alarmSetMessage.hpp>
#include <../common/messages/replyMessage.hpp>
#include <../common/subsystems/topology/topologyMessages.hpp>

#include <chrono>
#include <thread>

MessageHandler::MessageHandler(Message &&msg, QHostAddress fromAddr, Components& components)
    : mMsg(msg), mFromAddr(fromAddr), mComponents(components)
{
}

void MessageHandler::run()
{
//    qDebug() << "parsed message: "<< msg.toString();
    auto header = mMsg.getHeader();

    auto messageType = header.getType();

    if(isHeatingMessage(messageType))
    {
        mComponents.getHeatingApp().handleMessage(mMsg, mFromAddr);
    }
    else if(isLightsMessage(messageType))
    {
        mComponents.getLightsApp().handleMessage(mMsg, mFromAddr);
    }
    else if(messageType == MessageType::TOPOLOGY_REQUEST_CHECKIN)
    {
        {
            TopologyCheckInMessage message;

            if(mFromAddr != mComponents.getMasterAddress())
            {
                mComponents.setMasterAddress(mFromAddr);
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
    else if(messageType == MessageType::TOPOLOGY_MASTER_SHUTDOWN)
    {
        mComponents.setDataInitPhase(DataInitPhase::UNINITIALIZED);
    }
}
