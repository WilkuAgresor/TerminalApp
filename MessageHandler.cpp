#include <MessageHandler.hpp>
#include <../common/subsystems/alarm/alarmSetMessage.hpp>
#include <../common/messages/replyMessage.hpp>

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
}
