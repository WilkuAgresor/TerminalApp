#pragma once
#include <lights/lightControllers/ILightController.hpp>
#include <QObject>

class SimpleLightController : public ILightController
{
    Q_OBJECT
public:
    SimpleLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;

    virtual void handleSettingsChange(const LightControllerSettings& settings) override;

    ~SimpleLightController();
};

