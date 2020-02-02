#include <heating/HeatingCurrentView.hpp>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <../common/subsystems/heating/HeatingRetrieveMessage.hpp>
#include <Components.hpp>
#include <../common/messages/replyMessage.hpp>
#include <QtConcurrent/QtConcurrent>

HeatingCurrentView::HeatingCurrentView(QObject* parent, QObject * rootView, Components* components)
    : QObject(parent), mComponents(components)
{
    mSetterObject = rootView->findChild<QObject*>("heatingSetWidget", Qt::FindChildOption::FindChildrenRecursively);
    mCurrentObject = rootView->findChild<QObject*>("heatingCurTemp", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mSetterObject, SIGNAL(applyMultiSetter(int)), this, SLOT(applyMultiSetter(int)), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(selectAll()), this, SLOT(setAllForMultiUpdate()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(unselectAll()), this, SLOT(resetAllForMultiUpdate()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(saveChanges()), this, SLOT(saveCurrentSettings()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(resetChanges()), this, SLOT(resetCurrentSettings()), Qt::QueuedConnection);
    QObject::connect(mSetterObject, SIGNAL(selectedHeatingMode(int)), this, SLOT(handleProfileSelection(int)), Qt::DirectConnection);
    QObject::connect(mCurrentObject, SIGNAL(planeChanged(int)), this, SLOT(handlePlaneChange(int)), Qt::DirectConnection);


    mZoneFrontControl = new ZoneControl(mSetterObject, mCurrentObject, this);

//    for(auto& roomId: sHeatingIds)
//    {
//        qDebug() << roomId;
//        auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(parent, mSetterObject, roomId));
//        mRoomSettings.emplace_back(std::move(roomSetting));
//    }
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
    QMetaObject::invokeMethod(mSetterObject, "setBusy", Qt::QueuedConnection,
                              Q_ARG(QVariant, QVariant(value)));
}

void HeatingCurrentView::handleProfileSelection(int profileId)
{
    setBusy(true);

    qDebug() << "profile selected: "<< profileId;
    mCurrentHeatingProfile = profileId;
    HeatRetrievePayload payload(profileId+1);

    qDebug () << "sending to: "<<mComponents->getMasterAddress().toString()<< ":"<<mComponents->getMasterPort();
    HeatRetrieveMessage request(payload);

    auto responseBytes = mComponents->getSender().sendReceive(mComponents->getMasterAddress(), mComponents->getMasterPort(), request);
    Message msg(responseBytes);
    auto header = msg.getHeader();

    if(header.getType() == MessageType::HEAT_SETTINGS_UPDATE)
    {
        auto& message = static_cast<HeatSettingsMessage&>(msg);
        auto payload = message.payload();
        qDebug() <<"got reply: "<<message.toString();

        mZoneFrontControl->addOrUpdateZoneSetting(payload.mZoneSettings);
    }
    setBusy(false);
}

void HeatingCurrentView::handlePlaneChange(int selectedPlane)
{
    qDebug() << "plane changed to: " << selectedPlane;
    mZoneFrontControl->handlePlaneChange(selectedPlane);
}

void HeatingCurrentView::multiSelectClicked(QString roomId)
{
    mZoneFrontControl->checkForMultiUpdate(roomId);
}
void HeatingCurrentView::setAllForMultiUpdate()
{
    mZoneFrontControl->setAllForMultiUpdate();
}

void HeatingCurrentView::resetAllForMultiUpdate()
{
    mZoneFrontControl->resetAllForMultiUpdate();
}

void HeatingCurrentView::saveCurrentSettings()
{
    setBusy(true);
    QtConcurrent::run([this]{
        qDebug() << "save current settings to the DB";
        HeatSettingsPayload payload;
        payload.mMasterOn = mMasterOn;

        payload.mZoneSettings = mZoneFrontControl->getAllZoneSettings();

        payload.mProfiles.push_back(HeatProfile(mCurrentHeatingProfile+1, ""));
        HeatSettingsMessage message(payload);

        auto response = mComponents->getSender().sendReceive(mComponents->getMasterAddress(), mComponents->getMasterPort(), message);
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
        setBusy(false);
      });
}

void HeatingCurrentView::resetCurrentSettings()
{
    qDebug() << "Retrieve and Reload the settings from the DB";
    handleProfileSelection(mCurrentHeatingProfile);
}

void HeatingCurrentView::applyMultiSetter(int value)
{
    qDebug() << "applyMultisetter with value :" <<value;
    mZoneFrontControl->applyMultiSetter(value);

}

void HeatingCurrentView::setHeatZoneSettings(const std::vector<HeatZoneSetting>& settings)
{
    mZoneFrontControl->addOrUpdateZoneSetting(settings);
}

int HeatingCurrentView::getCurrentProfileId()
{
    return mCurrentHeatingProfile;
}
