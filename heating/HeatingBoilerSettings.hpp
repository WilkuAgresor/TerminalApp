#pragma once

#include <QObject>
#include <QString>
#include <QDebug>

#include <../common/subsystems/heating/BoilerSettingsMessage.hpp>

struct Components;

class HeatingBoilerSettings : public QObject
{
    Q_OBJECT
public:
    HeatingBoilerSettings(QObject *parent, QObject *rootView, Components* components);

    void handleSettingsMessage(const BoilerSettingsMessage &boilerSettings);

public slots:
    void handleHeatingModeChange(bool value);
    void handleCentralHeatingTempChange(int value);
    void handleCentralHeatingPumpChange(int index, bool value);
    void handleAntiLegionellaModeChange(bool value);
    void handleHotWaterTempChange(int value);

private:
    void setValue(const QString& name, const QVariant& value);

private:
    QObject* mRootView;
    Components* mComponents;

    QObject* mBoilerSettingsView;
};
