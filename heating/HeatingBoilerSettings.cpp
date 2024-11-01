#include "HeatingBoilerSettings.hpp"

#include <Components.hpp>
#include <QVariant>


HeatingBoilerSettings::HeatingBoilerSettings(QObject *parent, QObject *rootView, Components *components)
    : QObject(parent)
    , mRootView(rootView)
    , mComponents(components)
{
    mBoilerSettingsView = rootView->findChild<QObject*>("boilerSettings", Qt::FindChildOption::FindChildrenRecursively);
    if(!mBoilerSettingsView)
    {
        qDebug()<<"Failed to find boiler settings view";
    }

    QObject::connect(mBoilerSettingsView, SIGNAL(centralHeatingModeChange(bool)), this, SLOT(handleHeatingModeChange(bool)), Qt::QueuedConnection);
    QObject::connect(mBoilerSettingsView, SIGNAL(centralHeatingTempSetChange(int)), this, SLOT(handleCentralHeatingTempChange(int)), Qt::QueuedConnection);
    QObject::connect(mBoilerSettingsView, SIGNAL(centralHeatingPumpChange(int,bool)), this, SLOT(handleCentralHeatingPumpChange(int,bool)), Qt::QueuedConnection);
    QObject::connect(mBoilerSettingsView, SIGNAL(antiLegionellaModeChange(bool)), this, SLOT(handleAntiLegionellaModeChange(bool)), Qt::QueuedConnection);
    QObject::connect(mBoilerSettingsView, SIGNAL(hotWaterTempSetChange(int)), this, SLOT(handleHotWaterTempChange(int)), Qt::QueuedConnection);
}

void HeatingBoilerSettings::handleSettingsMessage(const BoilerSettingsMessage &message)
{    
    auto boilerSettings = message.payload();

    qDebug() <<"Receiver boiler settings refresh: "<<boilerSettings.toString();

    if(boilerSettings.mEnableCentralHeatingChanged)
    {
        setValue(JSON_ENABLE_CENTRAL_HEATING, boilerSettings.getEnableCentralHeating());
    }
    if(boilerSettings.mCentralHeatingTempSetChanged)
    {
        setValue(JSON_CENTRAL_HEATING_TEMP_SET, boilerSettings.getCentralHeatingTempSet());
    }
    if(boilerSettings.mMaxCentralHeatingTempSetChanged)
    {
        setValue(JSON_MAX_CENTRAL_HEATING_TEMP_SET, boilerSettings.getMaxCentralHeatingTempSet());
    }
    if(boilerSettings.mHotWaterTempSetChanged)
    {
        setValue(JSON_HOT_WATER_TEMP_SET, boilerSettings.getHotWaterTempSet());
    }

    setValue(JSON_IS_CENTRAL_HEATING_ON, boilerSettings.getIsCentralHeatingOn());
    setValue(JSON_IS_FLAME_ON, boilerSettings.getIsFlameOn());
    setValue(JSON_IS_HOT_WATER_ON, boilerSettings.getIsHotWaterOn());
    setValue(JSON_HOT_WATER_TEMP, boilerSettings.getHotWaterTemp());
    setValue(JSON_CENTRAL_HEATING_TEMP, boilerSettings.getCentralHeatingTemp());
    setValue(JSON_RETURN_TEMP, boilerSettings.getReturnTemp());
    setValue(JSON_PRESSURE, boilerSettings.getPressure());

    switch(boilerSettings.getConnectionStatus())
    {
    case 0:
        setValue("conStat", "Połączono");
        break;
    case 1:
        setValue("conStat", "Nieznany błąd");
        break;
    case 2:
        setValue("conStat", "INVALID");
        break;
    case 3:
        setValue("conStat", "TIMEOUT");
        break;
    default:
        setValue("conStat", "Poza zakresem");
        break;
    }

    qDebug() << "Boiler settings refreshed";
}

void HeatingBoilerSettings::handleHeatingModeChange(bool value)
{
    qDebug() <<"heating mode change received: "<<value;
    BoilerSettingsPayload payload;
    payload.setEnableCentralHeating(value);

    BoilerSettingsMessage request(payload);
    auto sendResult = mComponents->getSender().send(mComponents->getMasterAddress(), mComponents->getMasterPort(), request.toData());

    if(!sendResult)
    {
        qDebug() << "Failed to send heating mode change";
    }
}

void HeatingBoilerSettings::handleCentralHeatingTempChange(int value)
{
    qDebug() <<"central heating temperature change received: "<<value;
    BoilerSettingsPayload payload;
    payload.setCentralHeatingTempSet(value);

    BoilerSettingsMessage request(payload);
    auto sendResult = mComponents->getSender().send(mComponents->getMasterAddress(), mComponents->getMasterPort(), request.toData());

    if(!sendResult)
    {
        qDebug() << "Failed to send heating temperature change";
    }
}

void HeatingBoilerSettings::handleCentralHeatingPumpChange(int index, bool value)
{
    qDebug() <<"central heating pump change received: "<<index << ": "<<value;
}

void HeatingBoilerSettings::handleAntiLegionellaModeChange(bool value)
{
    qDebug() <<"antilegionella mode change received: "<<value;
}

void HeatingBoilerSettings::handleHotWaterTempChange(int value)
{
    qDebug() <<"hot water temperature change received: "<<value;
    BoilerSettingsPayload payload;
    payload.setHotWaterTempSet(value);

    BoilerSettingsMessage request(payload);
    auto sendResult = mComponents->getSender().send(mComponents->getMasterAddress(), mComponents->getMasterPort(), request.toData());

    if(!sendResult)
    {
        qDebug() << "Failed to send hot water temperature change";
    }
}

void HeatingBoilerSettings::setValue(const QString &name, const QVariant &value)
{
    if(mBoilerSettingsView)
    {
        mBoilerSettingsView->setProperty(name.toStdString().c_str(), value);
    }
}
