#pragma once

#include <lights/lightControllers/SimpleLightController.hpp>

class DimmableLightController : public SimpleLightController
{
    Q_OBJECT
public:
    DimmableLightController(QObject* parent, QObject* lightsViewObject, Components* components, const LightControllerSettings& settings);
    virtual void init() override;

    ~DimmableLightController();

    void setDimm(int dimm);

    virtual void handleSettingsChange(const LightControllerSettings &settings) override;


public slots:
    void handleDimmChange(int dimm);

private:
    int mDimm;
};

