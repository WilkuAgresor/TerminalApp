#include <heating/ZoneSetting.hpp>
#include <QSpinBox>

RoomSetting::RoomSetting(QObject *parent, QObject *rootObject, QString roomId, int setTemp, bool isOn)
    :QObject(parent), mHeatingObject(rootObject), id(roomId), mSetTemperature(setTemp), mIsOn(isOn)
{
    QMetaObject::invokeMethod(rootObject, "addZoneControlPanel", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(id)),
                              Q_ARG(QVariant, QVariant(mSetTemperature)),
                              Q_ARG(QVariant, QVariant(mIsOn)));

    mFrontObject = mHeatingObject->findChild<QObject*>(HEATING_ZONE_ID_PREFIX + id, Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mFrontObject, SIGNAL(valueChanged(int)), this, SLOT(handleSetValueChanged(int)));
    QObject::connect(mFrontObject, SIGNAL(switchedOnOff(bool)), this, SLOT(handleSwitchedOnOff(bool)));

    auto buttonObject = mFrontObject->findChild<QObject*>(HEATING_ZONE_MULTI_SET_BUTTON_ID, Qt::FindChildOption::FindChildrenRecursively);
    if(buttonObject)
    {
        QObject::connect(buttonObject, SIGNAL(clicked()), this, SLOT(handleSelectedForMultiUpdate()));
    }
}

QString RoomSetting::formatTemperature(double temp)
{
    QString text = QString().setNum(temp, 'f', 2);
    text.append('\xB0');
    text.append(" C");
    return text;
}

void RoomSetting::setCurrentTemperature(double temp)
{   
    QMetaObject::invokeMethod(mFrontObject, "setCurTemp", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(formatTemperature(temp))));
}

void RoomSetting::setSetterTemperature(quint16 setTemp)
{
    mSetTemperature = setTemp;
    QMetaObject::invokeMethod(mFrontObject, "setSetterValue", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(setTemp)));
}

quint16 RoomSetting::getSetterTemperature()
{
//    return setterObject->property("value").toUInt();
    return 1;
}

void RoomSetting::selectForMultiUpdate()
{
    QMetaObject::invokeMethod(mFrontObject, "checkForMultiUpdate", Qt::DirectConnection);
    mIsSelectedForMultiUpdate = true;
}

void RoomSetting::unselectForMultiUpdate()
{
    QMetaObject::invokeMethod(mFrontObject, "uncheckForMultiUpdate", Qt::DirectConnection);
    mIsSelectedForMultiUpdate = false;
}

bool RoomSetting::isSelectedForMultiUpdate()
{
    return mIsSelectedForMultiUpdate;
}

HeatZoneSetting RoomSetting::getZoneSetting()
{
    return HeatZoneSetting(mSetTemperature, mIsOn, id);
}

void RoomSetting::handleSelectedForMultiUpdate()
{
    qDebug() << "Selected for multi update: "<<id;
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
        qDebug() << "zone " << id<<" switched on";
    }
    else
    {
        qDebug() << "zone " << id<<" switched off";
    }
}

