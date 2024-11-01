#pragma once
#include <QObject>
#include <../common/subsystems/AppBase.hpp>


class Components;

class ProximityMonitor : public AppBase
{
    Q_OBJECT
public:
    ProximityMonitor(QObject* parent, Components* components);
    virtual ~ProximityMonitor();

    void run();

signals:
    void proximityChange(bool active);

private:
};

