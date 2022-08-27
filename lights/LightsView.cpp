#include "LightsView.hpp"

#include <lights/lightControllers/ColorLightController.hpp>


#include <Components.hpp>


LightsView::LightsView(QObject *parent, QObject *rootView, Components *components)
    : QObject(parent)
    , mComponents(components)
{
    mLightsView = rootView->findChild<QObject*>("lightsMainView", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mLightsView, SIGNAL(planeChanged(int)), this, SLOT(handlePlaneChange(int)), Qt::DirectConnection);
    QObject::connect(mLightsView, SIGNAL(guiSettingsChange(QString, int, int, int)), this, SLOT(handleGuiSettingsChange(QString, int, int, int)), Qt::DirectConnection);

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
    populateSettingsSelector();
}

void LightsView::handlePlaneChange(int selectedPlane)
{
    for(auto& lightController: mLightControllers)
    {
        lightController->handlePlaneChange(selectedPlane);
    }
}

void LightsView::handleGuiSettingsChange(QString name, int x, int y, int plane)
{
    qDebug() << "settings change: "<<name <<" x:" <<x<<" y:"<<y<<" plane:"<<plane;


    auto result = std::find_if(mLightControllers.begin(), mLightControllers.end(),
        [&name](const std::unique_ptr<ILightController>& x) { return x->getName() == name;});

    if(result != mLightControllers.end())
    {
        auto controller = result->get();
        auto pendingSettings = controller->getControllerSettings().constructEmptySettingsWithId();
        LightControllerGuiSettings guiSettings;
        guiSettings.mX = x;
        guiSettings.mY = y;
        guiSettings.mPlane = plane;
        pendingSettings.setGuiSettings(guiSettings);
        controller->commitChangedSettings(pendingSettings);
    }
}

void LightsView::addLightController(const LightControllerSettings &settings)
{
    switch(settings.mType)
    {
    case LightControllerType::BASIC:
    {
        auto lightController = std::unique_ptr<ILightController>(new SimpleLightController(this, mLightsView, mComponents, settings));
        static_cast<SimpleLightController&>(*lightController).init();

        lightController->handlePlaneChange(mActivePlane);

        mLightControllers.emplace_back(std::move(lightController));
    }
        break;
    case LightControllerType::DIMM:
    {
        auto lightController = std::unique_ptr<ILightController>(new DimmableLightController(this, mLightsView, mComponents, settings));
        static_cast<DimmableLightController&>(*lightController).init();

        lightController->handlePlaneChange(mActivePlane);
        mLightControllers.emplace_back(std::move(lightController));
    }
        break;
    case LightControllerType::COLOR:
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

void LightsView::populateSettingsSelector()
{
    QStringList list;
    list.push_back("NONE");
    for(const auto& controller: mLightControllers)
    {
        list.push_back(controller->getName());
    }

    if(mLightsView)
    {
        QMetaObject::invokeMethod(mLightsView, "populateSettingsSelector", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(list)));
    }
}
