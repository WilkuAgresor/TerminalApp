#include "SimpleLightController.hpp"
#include <QtConcurrent/QtConcurrent>


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
        else
        {
            QObject::connect(mControllerObject, SIGNAL(lightOnChanged(bool)), this, SLOT(handleOnChangeFromGui(bool)));
        }
    }
}

void SimpleLightController::handleSettingsChangeFromController(const LightControllerSettings &settings)
{
    if(settings.mIsOnChanged)
    {
        mControllerSettings.mIsOn = settings.mIsOn;
        setIsOnToGui(settings.mIsOn);
    }
    ILightController::handleSettingsChangeFromController(settings);
}

void SimpleLightController::setIsOnToGui(bool isOn)
{
    QMetaObject::invokeMethod(mControllerObject, "setStateInternal", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(isOn)));
}

void SimpleLightController::handleOnChangeFromGui(bool isOn)
{
    auto settings = mControllerSettings.constructEmptySettingsWithId();
    settings.setIsOn(!isOn);
    commitChangedSettings(settings);
}

SimpleLightController::~SimpleLightController()
{
}
