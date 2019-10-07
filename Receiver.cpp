#include <Receiver.hpp>
#include <MessageHandler.hpp>

TerminalReceiver::TerminalReceiver(QObject *parent, Components& components)
    : Receiver(TERMINAL_LISTEN_PORT, parent),
      mComponents(components)
{

}

void TerminalReceiver::handleMessage(QNetworkDatagram msg)
{
    qDebug() << "Handling incoming message";
    try
    {
        auto messageHandler = new MessageHandler(msg, mComponents);
        messageHandler->run();

//        messageHandler->setAutoDelete(true);
////        connect(messageHandler, SIGNAL(result(QNetworkDatagram)), this, SLOT(sendResponse(QNetworkDatagram)),Qt::QueuedConnection);
//        QThreadPool::globalInstance()->start(messageHandler);
    }
    catch (const std::exception& ex)
    {
        qDebug() << ex.what();
    }
}
