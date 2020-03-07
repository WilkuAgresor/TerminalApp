#pragma once

#include "DimmableLightController.hpp"

class ColorLightController : public DimmableLightController
{
    Q_OBJECT
public:
    ColorLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;
    ~ColorLightController();

    virtual void handleSettingsChangeFromController(const LightControllerSettings &settings) override;

    void setColorToGui(const QString &color);
public slots:
    void handleColorChangeFromGui(QString color);
private:
};

