#pragma once

#include <../common/receiver/receiver.hpp>

#include <Components.hpp>
class TerminalReceiver : public Receiver
{
public:
    TerminalReceiver(QObject *parent, ReceivePortsBank& networkPortBank, Components& components);
    ~TerminalReceiver() override = default;

    void handleMessage(Message msg, QHostAddress fromAddr) override;
private:
    Components& mComponents;
};
