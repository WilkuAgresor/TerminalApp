#pragma once

#include <QObject>
#include <../common/subsystems/heating/UpdateCurTemp.hpp>
#include <heating/HeatingCurrentView.hpp>


class HeatingApp : public QObject
{
public:
    HeatingApp(QObject* rootObject, QObject* parent);
    ~HeatingApp() = default;

    void handleMessage(const Message& message);
private:
    void handleStatusUpdateMessage(const HeatStatusMessage& message);

    QObject* mRootObject;
    HeatingCurrentView* mCurrentView;
    HeatingProfile* mHeatingProfile;
};
