#pragma once
#include <QObject>
#include <../common/subsystems/AppBase.hpp>
#include <QQmlEngine>


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

    QObject* mGrid;
    QQmlEngine mEngine;
    std::vector<QObject*> mCameras;

};
