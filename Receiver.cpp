#include <Receiver.hpp>
#include <MessageHandler.hpp>

TerminalReceiver::TerminalReceiver(QObject *parent, ReceivePortsBank &networkPortBank, Components& components)
    : Receiver(TERMINAL_LISTEN_PORT, networkPortBank, parent),
      mComponents(components)
{

}

void TerminalReceiver::handleMessage(Message msg, QHostAddress fromAddr)
{
    try
    {
        auto messageHandler = new MessageHandler(std::move(msg), fromAddr, mComponents);
        messageHandler->setAutoDelete(true);
        messageHandler->run();
    }
    catch (const std::exception& ex)
    {
        qDebug() << ex.what();
    }
}
