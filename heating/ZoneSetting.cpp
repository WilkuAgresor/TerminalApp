#include <heating/ZoneSetting.hpp>
#include <QSpinBox>

RoomSetting::RoomSetting(QObject *parent, QObject *rootObject, QString roomId)
    :QObject(parent), mHeatingObject(rootObject), id(roomId)
{
    QMetaObject::invokeMethod(rootObject, "addZoneControlPanel", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(id)),
                              Q_ARG(QVariant, QVariant(2350)),
                              Q_ARG(QVariant, QVariant(formatTemperature(23))));

    mFrontObject = mHeatingObject->findChild<QObject*>(HEATING_ZONE_ID_PREFIX + id, Qt::FindChildOption::FindChildrenRecursively);

    if(mFrontObject)
    {
        qDebug() << "front object found";
    }

    QObject::connect(mFrontObject, SIGNAL(valueChanged(int)), this, SLOT(handleSetValueChanged(int)));

    auto buttonObject = mFrontObject->findChild<QObject*>(HEATING_ZONE_MULTI_SET_BUTTON_ID, Qt::FindChildOption::FindChildrenRecursively);
    if(buttonObject)
    {
        qDebug() << "found button object";
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

void RoomSetting::handleSelectedForMultiUpdate()
{
    qDebug() << "Selected for multi update: "<<id;
    mIsSelectedForMultiUpdate = !mIsSelectedForMultiUpdate;
}

void RoomSetting::handleSetValueChanged(int newValue)
{
    qDebug() << "set value changed to" << newValue;
}

