#pragma once
#include <QObject>
#include <../common/subsystems/AppBase.hpp>

class Components;

class MonitoringApp : public AppBase
{
    Q_OBJECT
public:
    MonitoringApp(QObject* parent, Components* components, QObject* rootView);
    virtual ~MonitoringApp() = default;

    void run();

private:
    QObject* mRootView;
    QObject* mCamerasMainPage;
};
