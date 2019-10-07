#pragma once

#include <../common/receiver/receiver.hpp>

#include <Components.hpp>
class TerminalReceiver : public Receiver
{
public:
    TerminalReceiver(QObject *parent, Components& components);
    ~TerminalReceiver() override = default;

    void handleMessage(QNetworkDatagram msg) override;
private:
    Components& mComponents;
};
