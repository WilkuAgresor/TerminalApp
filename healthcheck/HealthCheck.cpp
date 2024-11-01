#include "HealthCheck.hpp"

#include <Components.hpp>
#include <thread>
#include <chrono>
#include <QProcess>

HealthCheck::HealthCheck(QObject *parent, Components* components)
    : AppBase(parent, components)
{
}

HealthCheck::~HealthCheck()
{
}

void HealthCheck::run()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // std::this_thread::sleep_for(std::chrono::seconds(15));

        // QProcess process;
        // process.startCommand(R"(/bin/bash -c "journalctl --since '15 seconds ago' | grep 'Failed to allocate DLIST entry'")");
        // process.waitForFinished();

        // QString output = process.readAllStandardOutput();

        // if(!output.isEmpty())
        // {
        //     qDebug() << "Graphics error detected. Rebooting now...";
        //     QProcess::execute("reboot");
        //     break;
        // }
    }
}
