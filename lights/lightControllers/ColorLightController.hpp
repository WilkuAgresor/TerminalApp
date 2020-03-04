#pragma once

#include "DimmableLightController.hpp"

class ColorLightController : public DimmableLightController
{
    Q_OBJECT
public:
    ColorLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;
    ~ColorLightController();

    virtual void handleSettingsChange(const LightControllerSettings &settings) override;

private:
};

