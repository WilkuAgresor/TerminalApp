#pragma once

#include <QRunnable>
#include <QObject>
#include <QDebug>
#include <QUdpSocket>
#include <QNetworkDatagram>

#include <Components.hpp>

class MessageHandler : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MessageHandler(QNetworkDatagram datagram, Components &components);
    ~MessageHandler() = default;
    void run();

signals:
    void result(QNetworkDatagram datagram);
private:
    QNetworkDatagram mDatagram;
    Components& mComponents;
};

