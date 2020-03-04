#pragma once

#include <QObject>
#include <lights/lightControllers/ILightController.hpp>
#include <memory>

class Components;

class LightsView : public QObject
{
    Q_OBJECT
public:
    LightsView(QObject* parent, QObject * rootView, Components* components);
    void handleSettingsChange(const std::vector<LightControllerSettings>& settings);
public slots:
    void handlePlaneChange(int selectedPlane);
private:
    void addLightController(const LightControllerSettings& settings);

    int mActivePlane = 0;
    Components* mComponents;
    QObject* mLightsView;
    std::vector<std::unique_ptr<ILightController>> mLightControllers;
};
