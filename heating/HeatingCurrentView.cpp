#include <heating/HeatingCurrentView.hpp>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <Components.hpp>
#include <../common/messages/replyMessage.hpp>
#include <QtConcurrent/QtConcurrent>

HeatingCurrentView::HeatingCurrentView(QObject* parent, QObject * rootView, Components* components)
    : QObject(parent), mComponents(components)
{
    mSetterObject = rootView->findChild<QObject*>("heatingSetWidget", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mSetterObject, SIGNAL(applyMultiSetter(int)), this, SLOT(applyMultiSetter(int)), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(selectAll()), this, SLOT(setAllForMultiUpdate()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(unselectAll()), this, SLOT(resetAllForMultiUpdate()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(saveChanges()), this, SLOT(saveCurrentSettings()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(resetChanges()), this, SLOT(resetCurrentSettings()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(selectedHeatingMode(int)), this, SLOT(handleProfileSelection(int)), Qt::QueuedConnection);

//    for(auto& roomId: sHeatingIds)
//    {
//        qDebug() << roomId;
//        auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(parent, mSetterObject, roomId));
//        mRoomSettings.emplace_back(std::move(roomSetting));
//    }
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

void HeatingCurrentView::addZoneSettingObject(const HeatZoneSetting &setting)
{     
    auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(this, mSetterObject, setting.mZoneId, setting.mSetTemperature, setting.mIsOn));
    mRoomSettings.emplace_back(std::move(roomSetting));
}

void HeatingCurrentView::setProfileList(const std::vector<HeatProfile> &profiles)
{
    QMetaObject::invokeMethod(mSetterObject, "clearProfiles", Qt::DirectConnection);
    for(auto& profile: profiles)
    {
        QMetaObject::invokeMethod(mSetterObject, "addProfile", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(profile.mName)));
    }
    QMetaObject::invokeMethod(mSetterObject, "selectProfile", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(0)));
}

void HeatingCurrentView::setBusy(bool value)
{
    QMetaObject::invokeMethod(mSetterObject, "setBusy", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(value)));
}

void HeatingCurrentView::handleProfileSelection(int profileId)
{
    setBusy(true);
    //retrieve profile data
    qDebug() << "profile selected: "<< profileId;
    mCurrentHeatingProfile = profileId;
    setBusy(false);
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
    QtConcurrent::run([this]{
        qDebug() << "save current settings to the DB";
        HeatSettingsPayload payload;
        payload.mMasterOn = mMasterOn;

        for(auto& zone: mRoomSettings)
        {
            payload.mZoneSettings.push_back(zone->getZoneSetting());
        }
        payload.mProfiles.push_back(HeatProfile(mCurrentHeatingProfile+1, ""));
        HeatSettingsMessage message(payload);

        auto response = mComponents->getSender().sendReceive(mComponents->getMasterAddress(), SERVER_LISTEN_PORT, message);
        Message msg(response);
        auto header = msg.getHeader();
        if(header.getType() == MessageType::REPLY)
        {
            auto& respMsg = static_cast<ReplyMessage&>(msg);
            auto payload = respMsg.payload();
            if(payload.mStatus == Status::OK)
            {
                qDebug() << "configuration applied successfully";
            }
            else
            {
                qDebug() << "configuration was not applied";
            }
        }
      });
}

void HeatingCurrentView::resetCurrentSettings()
{
    qDebug() << "Retrieve and Reload the settings from the DB";
    setBusy(false);
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
