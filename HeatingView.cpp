#include "HeatingView.hpp"
#include <Dictionary.hpp>

Heating::Heating(QObject * rootView)
    : QObject(rootView)
{
    mHeatingObject = rootView->findChild<QObject*>("heatingForm", Qt::FindChildOption::FindChildrenRecursively);
    mMultiSetterObject = rootView->findChild<QObject*>("multiSetter", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mHeatingObject, SIGNAL(buttonClicked(QString)), this, SLOT(multiSelectClicked(QString)));
    QObject::connect(mHeatingObject, SIGNAL(applyMultiSetter()), this, SLOT(applyMultiSetter()));



    qDebug() << "room id loop";


    for(auto& roomId: sHeatingIds)
    {
        qDebug() << roomId;
        auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(mHeatingObject, roomId));
        mRoomSettings.emplace_back(std::move(roomSetting));
    }
}

void Heating::setRoomCurTemp(const QString &roomId, double temperature)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setCurrentTemperature(temperature);
}

void Heating::setRoomSetterTemperature(const QString &roomId, quint16 setting)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setSetterTemperature(setting);
}

void Heating::multiSelectClicked(QString roomId)
{
    qDebug() << "button clicked for room:" << roomId;
    auto room = findRoomById(roomId);
    if(room)
        room->checkForMultiSetter();
}

void Heating::applyMultiSetter()
{
    auto settingVariant = mMultiSetterObject->property("value");
    quint16 setting = settingVariant.toUInt();

    for(auto& room: mRoomSettings)
    {
        if(room->isCheckedForMultiSetter())
            room->setSetterTemperature(setting);
    }
}

RoomSetting *Heating::findRoomById(const QString &roomId)
{
    for(auto& room: mRoomSettings)
    {
        if(room->id == roomId)
        {
            return room.get();
        }
    }
    return nullptr;
}

RoomSetting::RoomSetting(QObject *parent, QString roomId)
    :QObject(parent), id(roomId)
{
    curTempObject = parent->findChild<QObject*>(roomId+HEATING_CUR_TEMP, Qt::FindChildOption::FindChildrenRecursively);
    setterObject = parent->findChild<QObject*>(roomId+HEATING_SETTER, Qt::FindChildOption::FindChildrenRecursively);
}

void RoomSetting::setCurrentTemperature(double temp)
{
    QString text = QString().setNum(temp, 'f', 2);
    text.append('\xB0');
    text.append(" C");
    curTempObject->setProperty("text", text);
}

void RoomSetting::setSetterTemperature(quint16 setTemp)
{
    setterObject->setProperty("value", setTemp);
}

void RoomSetting::checkForMultiSetter()
{
    mIsCheckedForMultiSetter = !mIsCheckedForMultiSetter;
}

bool RoomSetting::isCheckedForMultiSetter()
{
    return mIsCheckedForMultiSetter;
}


