#include "ColorLightController.hpp"
#include <QtConcurrent/QtConcurrent>

ColorLightController::ColorLightController(QObject *parent, QObject *lightsViewObject, Components* components, const LightControllerSettings &settings)
    : DimmableLightController(parent, lightsViewObject, components, settings)
{
}

ColorLightController::~ColorLightController()
{
}

void ColorLightController::handleSettingsChange(const LightControllerSettings &settings)
{
    //set color to gui

    DimmableLightController::handleSettingsChange(settings);
}

void ColorLightController::init()
{
    QMetaObject::invokeMethod(mLightsViewObject, "addColorLightController", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(QString::number(getId()))),
                              Q_ARG(QVariant, QVariant(getIsOn())),
                              Q_ARG(QVariant, QVariant(getGuiSettings().mX)),
                              Q_ARG(QVariant, QVariant(getGuiSettings().mY))
                              ,Q_ARG(QVariant, QVariant(getDimm())));
    mControllerObject = mLightsViewObject->findChild<QObject*>(LIGHTS_COLOR_CONTROLLER_PREFIX + QString::number(getId()), Qt::FindChildOption::FindChildrenRecursively);
    if(mControllerObject == nullptr)
    {
        qDebug() << "not found color light controller";
    }
    else
    {
        QObject::connect(mControllerObject, SIGNAL(lightDimmChanged(int)), this, SLOT(handleDimmChange(int)));
    }
}
