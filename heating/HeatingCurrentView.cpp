#include <heating/HeatingCurrentView.hpp>

#include <../common/subsystems/heating/HeatingDictionary.hpp>

HeatingCurrentView::HeatingCurrentView(QObject* parent, QObject * rootView)
    : QObject(parent)
{
    mSetterObject = rootView->findChild<QObject*>("heatingSetWidget", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mSetterObject, SIGNAL(applyMultiSetter(int)), this, SLOT(applyMultiSetter(int)));
    QObject::connect(mSetterObject, SIGNAL(selectAll()), this, SLOT(setAllForMultiUpdate()));
    QObject::connect(mSetterObject, SIGNAL(unselectAll()), this, SLOT(resetAllForMultiUpdate()));
    QObject::connect(mSetterObject, SIGNAL(saveChanges()), this, SLOT(saveCurrentSettings()));
    QObject::connect(mSetterObject, SIGNAL(resetChanges()), this, SLOT(resetCurrentSettings()));

    for(auto& roomId: sHeatingIds)
    {
        qDebug() << roomId;
        auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(parent, mSetterObject, roomId));
        mRoomSettings.emplace_back(std::move(roomSetting));
    }
}

void HeatingCurrentView::setRoomCurTemp(const QString &roomId, double temperature)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setCurrentTemperature(temperature);
}

void HeatingCurrentView::setRoomSetterTemperature(const QString &roomId, quint16 setting)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setSetterTemperature(setting);
}

//void HeatingCurrentView::setCurrentHeatingProfile(int id)
//{
//    qDebug() << "Current heating profile changed to: "<<id;
//    mCurrentHeatingProfile = id;
//}

void HeatingCurrentView::multiSelectClicked(QString roomId)
{
//    qDebug() << "multisetter clicked: " << roomId;
//    auto room = findRoomById(roomId);
//    if(room)
//        room->checkForMultiSetter();
}
void HeatingCurrentView::setAllForMultiUpdate()
{
    qDebug() << "select all for multiupdate";
    for(auto& zone: mRoomSettings)
    {
        zone->selectForMultiUpdate();
    }
}

void HeatingCurrentView::resetAllForMultiUpdate()
{
    for(auto& zone: mRoomSettings)
    {
        zone->unselectForMultiUpdate();
    }
}

void HeatingCurrentView::saveCurrentSettings()
{
    qDebug() << "save current settings to the DB";


}

void HeatingCurrentView::resetCurrentSettings()
{
    qDebug() << "Retrieve and Reload the settings from the DB";
}

void HeatingCurrentView::applyMultiSetter(int value)
{
    qDebug() << "applyMultisetter with value :" <<value;
    for(auto& zone: mRoomSettings)
    {
        if(zone->isSelectedForMultiUpdate())
            zone->setSetterTemperature(value);
    }
}

RoomSetting *HeatingCurrentView::findRoomById(const QString &roomId)
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

HeatingProfile::HeatingProfile(QObject *parent, QObject *rootObject)
    :QObject(parent)
{
}

//HeatingProfileType HeatingProfile::getCurrentProfile()
//{
//    return static_cast<HeatingProfileType>(profileObject->property("currentIndex").toUInt());
//}

//void HeatingProfile::setCurrentProfile(HeatingProfileType profile)
//{

//    qDebug() << "current prifile before: "<< static_cast<quint16>(getCurrentProfile());

//    if(profileObject)
//        profileObject->setProperty("currentIndex", static_cast<quint16>(profile));
//    else
//        qDebug() << "not found heating profile";


//    qDebug() << "current prifile after: "<< static_cast<quint16>(getCurrentProfile());
//}
