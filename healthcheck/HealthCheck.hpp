#pragma once
#include <QObject>
#include <../common/subsystems/AppBase.hpp>


class Components;

class HealthCheck : public AppBase
{
    Q_OBJECT
public:
    HealthCheck(QObject* parent, Components* components);
    virtual ~HealthCheck();

    void run();

private:
};

