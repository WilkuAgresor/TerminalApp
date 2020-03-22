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
            QObject::connect(mControllerObject, SIGNAL(lightDimmChanged(int)), this, SLOT(handleDimmChangeFromGui(int)));
            QObject::connect(mControllerObject, SIGNAL(lightOnChanged(bool)), this, SLOT(handleOnChangeFromGui(bool)));
        }
    }
}

DimmableLightController::~DimmableLightController()
{
}

//to gui
void DimmableLightController::setDimmToGui(int dimm)
{
    QMetaObject::invokeMethod(mControllerObject, "setDimm", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(dimm)));
}

//from controller
void DimmableLightController::handleSettingsChangeFromController(const LightControllerSettings &settings)
{
    qDebug() << "settings 2";

    if(settings.mDimmChanged && (settings.mDimm != mControllerSettings.mDimm))
    {
        mControllerSettings.mDimm = settings.mDimm;
        setDimmToGui(settings.mDimm);
    }
    SimpleLightController::handleSettingsChangeFromController(settings);
}

//from gui
void DimmableLightController::handleDimmChangeFromGui(int dimm)
{
    qDebug() << "change: "<<dimm;

    if(dimm != mControllerSettings.mDimm)
    {
        mControllerSettings.mDimm = dimm;

        auto settings = mControllerSettings.constructEmptySettingsWithId();
        settings.setDimm(dimm);
        commitChangedSettings(settings);
    }
}
