#include <heating/zoneSettings/ZoneSetting.hpp>
#include <QSpinBox>
#include <heating/HeatingCommon.hpp>

RoomSetting::RoomSetting(QObject *parent, QObject *setWidget, QObject *curWidget, QString zoneName, int zoneId, int curTemp, int setTemp, bool isOn, const HeatZoneGuiSettings &guiSettings)
    :QObject(parent), mSetterWidget(setWidget), mCurWidget(curWidget), mZoneName(zoneName), mZoneId(zoneId), mCurTemperature(curTemp), mSetTemperature(setTemp), mIsOn(isOn), mGuiSettings(guiSettings)
{
    QMetaObject::invokeMethod(setWidget, "addZoneControlPanel", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(mZoneName)),
                              Q_ARG(QVariant, QVariant(mSetTemperature)),
                              Q_ARG(QVariant, QVariant(mIsOn)));

    QMetaObject::invokeMethod(curWidget, "addCurTempWidget", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(mZoneName)),
                              Q_ARG(QVariant, QVariant(formatTemperature(mCurTemperature))),
                              Q_ARG(QVariant, QVariant(guiSettings.mPlane)),
                              Q_ARG(QVariant, QVariant(guiSettings.mX)),
                              Q_ARG(QVariant, QVariant(guiSettings.mY)),
                              Q_ARG(QVariant, QVariant(guiSettings.mHeight)),
                              Q_ARG(QVariant, QVariant(guiSettings.mWidth)),
                              Q_ARG(QVariant, QVariant(guiSettings.mFontSize))
                              );

    mZoneSetObject = mSetterWidget->findChild<QObject*>(HEATING_ZONE_ID_PREFIX + mZoneName, Qt::FindChildOption::FindChildrenRecursively);
    mZoneCurObject = mCurWidget->findChild<QObject*>(HEATING_ZONE_CUR_PREFIX + mZoneName, Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mZoneSetObject, SIGNAL(valueChanged(int)), this, SLOT(handleSetValueChanged(int)));
    QObject::connect(mZoneSetObject, SIGNAL(switchedOnOff(bool)), this, SLOT(handleSwitchedOnOff(bool)));

    auto buttonObject = mZoneSetObject->findChild<QObject*>(HEATING_ZONE_MULTI_SET_BUTTON_ID, Qt::FindChildOption::FindChildrenRecursively);
    if(buttonObject)
    {
        QObject::connect(buttonObject, SIGNAL(clicked()), this, SLOT(handleSelectedForMultiUpdate()));
    }
}

void RoomSetting::setCurrentTemperature(qint16 temp)
{   
    mCurTemperature = temp;
    QMetaObject::invokeMethod(mZoneCurObject, "setCurrentTemperature", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(formatTemperature(temp))));
}

void RoomSetting::setSetterTemperature(qint16 setTemp)
{
    mSetTemperature = setTemp;
    QMetaObject::invokeMethod(mZoneSetObject, "setSetterValue", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(setTemp)));
}

qint16 RoomSetting::getSetterTemperature()
{
    return mSetTemperature;
}

qint16 RoomSetting::getCurrentTemperature()
{
    return mCurTemperature;
}

void RoomSetting::checkForMultiSetter()
{
    if(mIsSelectedForMultiUpdate)
    {
        unselectForMultiUpdate();
    }
    else
    {
        selectForMultiUpdate();
    }
}

void RoomSetting::selectForMultiUpdate()
{
    QMetaObject::invokeMethod(mZoneSetObject, "checkForMultiUpdate", Qt::DirectConnection);
    mIsSelectedForMultiUpdate = true;
}

void RoomSetting::unselectForMultiUpdate()
{
    QMetaObject::invokeMethod(mZoneSetObject, "uncheckForMultiUpdate", Qt::DirectConnection);
    mIsSelectedForMultiUpdate = false;
}

bool RoomSetting::isSelectedForMultiUpdate()
{
    return mIsSelectedForMultiUpdate;
}

HeatZoneSetting RoomSetting::getZoneSetting()
{
    return HeatZoneSetting(mSetTemperature, mIsOn, mZoneName, mZoneId, mGuiSettings);
}

void RoomSetting::updateZoneSetting(const HeatZoneSetting& setting)
{
    if(setting.mSetTempChanged)
        setSetterTemperature(setting.mSetTemperature);
    if(setting.mCurrentTempChanged)
        setCurrentTemperature(setting.mCurrentTemp);
    if(setting.mIsOnChanged)
        setIsOn(setting.mIsOn);
}

void RoomSetting::setVisibility(bool isVisible)
{
    if(mZoneCurVisibility != isVisible)
    {
        QMetaObject::invokeMethod(mZoneCurObject, "setVisibility", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(isVisible)));
        mZoneCurVisibility = isVisible;
    }
}

void RoomSetting::handleSelectedForMultiUpdate()
{
    qDebug() << "Selected for multi update: "<<mZoneName;
    mIsSelectedForMultiUpdate = !mIsSelectedForMultiUpdate;
}

void RoomSetting::handleSetValueChanged(int newValue)
{
    qDebug() << "set value changed to" << newValue;
    mSetTemperature = newValue;
}

void RoomSetting::handleSwitchedOnOff(bool value)
{
    mIsOn = value;
    if(value)
    {
        qDebug() << "zone " << mZoneName<<" switched on";
    }
    else
    {
        qDebug() << "zone " << mZoneName<<" switched off";
    }
}

void RoomSetting::setIsOn(bool value)
{
    mIsOn = value;
    if(value)
    {
        QMetaObject::invokeMethod(mZoneSetObject, "setOn", Qt::DirectConnection);
    }
    else
    {
        QMetaObject::invokeMethod(mZoneSetObject, "setOff", Qt::DirectConnection);
    }
}

