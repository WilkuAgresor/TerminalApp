#pragma once
#include <lights/lightControllers/ILightController.hpp>
#include <QObject>

class SimpleLightController : public ILightController
{
    Q_OBJECT
public:
    SimpleLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;
    ~SimpleLightController();

    virtual void handleSettingsChangeFromController(const LightControllerSettings& settings) override;

    void setIsOnToGui(bool isOn);

public slots:
    void handleOnChangeFromGui(bool isOn);

};

