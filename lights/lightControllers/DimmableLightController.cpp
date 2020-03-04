#include "DimmableLightController.hpp"
#include <QtConcurrent/QtConcurrent>
#include <QDateTime>
#include <QJsonArray>

DimmableLightController::DimmableLightController(QObject *parent, QObject *lightsViewObject, Components* components, const LightControllerSettings &settings)
    : SimpleLightController(parent, lightsViewObject, components, settings)
    , mDimm(settings.mDimm/static_cast<double>(100))
{
}

void DimmableLightController::init()
{
    if(mControllerObject == nullptr)
    {
        QMetaObject::invokeMethod(mLightsViewObject, "addDimmableLightController", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(QString::number(getId()))),
                                  Q_ARG(QVariant, QVariant(getIsOn())),
                                  Q_ARG(QVariant, QVariant(getGuiSettings().mX)),
                                  Q_ARG(QVariant, QVariant(getGuiSettings().mY))
                                  ,Q_ARG(QVariant, QVariant(mDimm)));
        mControllerObject = mLightsViewObject->findChild<QObject*>(LIGHTS_DIMMABLE_CONTROLLER_PREFIX + QString::number(getId()), Qt::FindChildOption::FindChildrenRecursively);
        if(mControllerObject == nullptr)
        {
            qDebug() << "not found dimmable light controller";
        }
        else
        {
            QObject::connect(mControllerObject, SIGNAL(lightDimmChanged(int)), this, SLOT(handleDimmChange(int)));
        }
    }
}

DimmableLightController::~DimmableLightController()
{
}

//to gui
void DimmableLightController::setDimm(int dimm)
{
    QtConcurrent::run([&]{
        QMetaObject::invokeMethod(mControllerObject, "setDimm", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(dimm)));
    });
}

//from controller
void DimmableLightController::handleSettingsChange(const LightControllerSettings &settings)
{
    if(settings.mDimm != mControllerSettings.mDimm)
    {
        setDimm(settings.mDimm);
    }
    SimpleLightController::handleSettingsChange(settings);
}

//from gui
void DimmableLightController::handleDimmChange(int dimm)
{
    qDebug() << "change: "<<dimm;

    if(dimm != mControllerSettings.mDimm)
    {
        mControllerSettings.mDimm = dimm;
        commitChangedSettings(mControllerSettings);
    }
}
