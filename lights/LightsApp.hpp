#pragma once

#include <QObject>
#include <../common/subsystems/lights/LightControllerSettings.hpp>
#include <lights/LightsView.hpp>
#include <QNetworkDatagram>

class Components;

class LightsApp : public QObject
{
    Q_OBJECT
public:
    LightsApp(QObject* rootObject, QObject* parent, Components* components);
    ~LightsApp() = default;

    void handleMessage(const Message& message, const QHostAddress &fromAddress, int fromPort);
private:
    void handleReprovisionMessage(const LightSettingsMessage& message, const QHostAddress &fromAddress, int fromPort);

    Components* mComponents;
    QObject* mRootObject;
    LightsView mLightsView;
};
