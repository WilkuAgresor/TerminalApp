#include "ColorLightController.hpp"
#include <QtConcurrent/QtConcurrent>

ColorLightController::ColorLightController(QObject *parent, QObject *lightsViewObject, Components* components, const LightControllerSettings &settings)
    : DimmableLightController(parent, lightsViewObject, components, settings)
{
}

ColorLightController::~ColorLightController()
{
}

void ColorLightController::handleSettingsChangeFromController(const LightControllerSettings &settings)
{
    if(settings.mColor != getColor())
    {
        setColorToGui(settings.mColor);
    }
    DimmableLightController::handleSettingsChangeFromController(settings);
}

void ColorLightController::setColorToGui(const QString& color)
{
    QtConcurrent::run([&]{
        QMetaObject::invokeMethod(mControllerObject, "setColor", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(color)));
    });
}

void ColorLightController::handleColorChangeFromGui(QString color)
{
    if(color != mControllerSettings.mColor)
    {
        mControllerSettings.mColor = color;
        commitChangedSettings(mControllerSettings);
    }
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
        QObject::connect(mControllerObject, SIGNAL(lightColorChanged(QString)), this, SLOT(handleColorChangeFromGui(QString)));
        QObject::connect(mControllerObject, SIGNAL(lightDimmChanged(int)), this, SLOT(handleDimmChangeFromGui(int)));
        QObject::connect(mControllerObject, SIGNAL(lightOnChanged(bool)), this, SLOT(handleOnChangeFromGui(bool)));
    }
}
