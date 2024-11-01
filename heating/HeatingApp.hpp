#pragma once

#include <QObject>
#include <../common/subsystems/heating/HeatingZoneSettings.hpp>
#include <heating/HeatingCurrentView.hpp>
#include <heating/HeatingStatistics.hpp>
#include <heating/HeatingBoilerSettings.hpp>

#include <QNetworkDatagram>

class Components;

class HeatingApp : public QObject
{
public:
    HeatingApp(QObject* rootObject, QObject* parent, Components* components);
    ~HeatingApp() = default;

    void handleMessage(const Message& message, const QHostAddress &fromAddress);
private:
    void handleReprovisionMessage(const HeatSettingsMessage& message, const QHostAddress &fromAddress);
 //   void handleStatusUpdateMessage(const HeatStatusMessage& message);

    Components* mComponents;
    QObject* mRootObject;
    HeatingCurrentView* mCurrentView;
    HeatingStatistics* mStatistics;
    HeatingBoilerSettings* mBoilerSettings;

};
