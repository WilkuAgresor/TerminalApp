#include "LightsView.hpp"

#include <lights/lightControllers/ColorLightController.hpp>


#include <Components.hpp>


LightsView::LightsView(QObject *parent, QObject *rootView, Components *components)
    : QObject(parent)
    , mComponents(components)
{
    mLightsView = rootView->findChild<QObject*>("lightsMainView", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mLightsView, SIGNAL(planeChanged(int)), this, SLOT(handlePlaneChange(int)), Qt::DirectConnection);

    if(!mLightsView)
    {
        qDebug() << "not found lightsView";
    }

}

void LightsView::handleSettingsChange(const std::vector<LightControllerSettings> &settings)
{
    for(const auto& setting: settings)
    {
        auto it = std::find_if(mLightControllers.begin(), mLightControllers.end(),
                [&setting](const std::unique_ptr<ILightController>& x) { return x->getId() == setting.mId;});
        if(it != mLightControllers.end())
        {
            (*it)->handleSettingsChangeFromController(setting);
        }
        else
        {
            addLightController(setting);
        }
    }
}

void LightsView::handlePlaneChange(int selectedPlane)
{
    for(auto& lightController: mLightControllers)
    {
        lightController->handlePlaneChange(selectedPlane);
    }
}

void LightsView::addLightController(const LightControllerSettings &settings)
{
    switch(settings.mType)
    {
    case 0:
    {
        auto lightController = std::unique_ptr<ILightController>(new SimpleLightController(this, mLightsView, mComponents, settings));
        static_cast<SimpleLightController&>(*lightController).init();

        lightController->handlePlaneChange(mActivePlane);

        mLightControllers.emplace_back(std::move(lightController));
    }
        break;
    case 1:
    {
        auto lightController = std::unique_ptr<ILightController>(new DimmableLightController(this, mLightsView, mComponents, settings));
        static_cast<DimmableLightController&>(*lightController).init();

        lightController->handlePlaneChange(mActivePlane);
        mLightControllers.emplace_back(std::move(lightController));
    }
        break;
    case 2:
    {
        auto lightController = std::unique_ptr<ILightController>(new ColorLightController(this, mLightsView, mComponents, settings));
        static_cast<ColorLightController&>(*lightController).init();

        qDebug() << "name: "<<lightController->getName();
        lightController->handlePlaneChange(mActivePlane);
        mLightControllers.emplace_back(std::move(lightController));
    }
        break;
    default:
        qDebug() << "light type not supported yet";
        break;
    }
}
