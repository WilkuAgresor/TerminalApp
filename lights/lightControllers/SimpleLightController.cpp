#include "SimpleLightController.hpp"

SimpleLightController::SimpleLightController(QObject *parent, QObject *lightsViewObject, Components* components, const LightControllerSettings& settings)
    : ILightController(parent, lightsViewObject, components, settings)
{   
}

void SimpleLightController::init()
{
    if(mControllerObject == nullptr)
    {
        QMetaObject::invokeMethod(mLightsViewObject, "addSimpleLightController", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(QString::number(getId()))),
                                  Q_ARG(QVariant, QVariant(getIsOn())),
                                  Q_ARG(QVariant, QVariant(getGuiSettings().mX)),
                                  Q_ARG(QVariant, QVariant(getGuiSettings().mY)));
        mControllerObject = mLightsViewObject->findChild<QObject*>(LIGHTS_SIMPLE_CONTROLLER_PREFIX + QString::number(getId()), Qt::FindChildOption::FindChildrenRecursively);
        if(mControllerObject == nullptr)
        {
            qDebug() << "not found light controller";
        }
    }
}

void SimpleLightController::handleSettingsChange(const LightControllerSettings &settings)
{
    if(settings.mIsOn != getIsOn())
    {
        setIsOn(settings.mIsOn);
    }
}

SimpleLightController::~SimpleLightController()
{
}
