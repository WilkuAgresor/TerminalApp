#pragma once

#include <../common/subsystems/lights/LightControllerSettings.hpp>
#include <../common/subsystems/lights/LightsDictionary.hpp>

class Components;

class ILightController : public QObject
{
    Q_OBJECT
public:
    ILightController(QObject* parent, QObject* lightsView, Components* components, const LightControllerSettings& settings);
    virtual void init() = 0;

    virtual ~ILightController();
    int getType();
    int getId();
    QString getName();
    bool getIsOn();
    int getDimm();

    LightControllerGuiSettings getGuiSettings();
    void setIsOn(bool isOn);

    void handlePlaneChange(int selectedPlane);
    virtual void handleSettingsChange(const LightControllerSettings& settings);

    void commitChangedSettings(const LightControllerSettings &settings);
protected:
    QObject* mLightsViewObject;
    Components* mComponents;
    LightControllerSettings mControllerSettings;
    QObject* mControllerObject = nullptr;

};