#pragma once

#include <lights/lightControllers/SimpleLightController.hpp>

class DimmableLightController : public SimpleLightController
{
    Q_OBJECT
public:
    DimmableLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;

    ~DimmableLightController();

    void setDimmToGui(int dimm);

    virtual void handleSettingsChangeFromController(const LightControllerSettings &settings) override;

public slots:
    void handleDimmChangeFromGui(int dimm);

private:
    int mDimm;
};

