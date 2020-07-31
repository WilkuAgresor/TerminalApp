#include "ZoneControl.hpp"

ZoneControl::ZoneControl(QObject *setWidget, QObject *curTempWidget, QObject* parent)
    : QObject(parent),
      mSetWidgetPtr(setWidget),
      mCurTempWidgetPtr(curTempWidget)
{

}

void ZoneControl::clearZones()
{
    mRoomSettings.clear();
}

void ZoneControl::addOrUpdateZoneSetting(const std::vector<HeatZoneSetting> &settings)
{
    for(const auto& setting: settings)
    {
        addOrUpdateZoneSetting(setting);
    }
}

void ZoneControl::addOrUpdateZoneSetting(const HeatZoneSetting &setting)
{
    auto it = std::find_if(mRoomSettings.begin(), mRoomSettings.end(),
            [&setting](const std::unique_ptr<RoomSetting>& x) { return x->mZoneName == setting.mZoneName;});
    if(it != mRoomSettings.end())
    {
        (*it)->updateZoneSetting(setting);
    }
    else
    {
        addZoneSettingObject(setting);
    }
}

std::vector<HeatZoneSetting> ZoneControl::getAllZoneSettings()
{
    std::vector<HeatZoneSetting> settings;
    for(const auto& zone: mRoomSettings)
    {
        settings.emplace_back(zone->getZoneSetting());
    }
    return settings;
}

void ZoneControl::addZoneSettingObject(const HeatZoneSetting &setting)
{
    auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(this,
                                                                    mSetWidgetPtr,
                                                                    mCurTempWidgetPtr,
                                                                    setting.mZoneName,
                                                                    setting.mZoneId,
                                                                    setting.mCurrentTemp,
                                                                    setting.mSetTemperature,
                                                                    setting.mIsOn,
                                                                    setting.mGuiSettings));
    if(setting.mGuiSettings.mPlane == mCurrentPlane)
    {
        roomSetting->setVisibility(true);
    }
    mRoomSettings.emplace_back(std::move(roomSetting));
}

//void ZoneControl::setRoomCurTemp(const QString &roomId, double temperature)
//{
//    auto room = findRoomById(roomId);

//    if(room)
//        room->setCurrentTemperature(temperature);
//}

//void ZoneControl::setRoomSetterTemperature(const QString &roomId, quint16 setting)
//{
//    auto room = findRoomById(roomId);

//    if(room)
//        room->setSetterTemperature(setting);
//}

void ZoneControl::setAllForMultiUpdate()
{
    qDebug() << "select all for multiupdate";
    for(auto& zone: mRoomSettings)
    {
        zone->selectForMultiUpdate();
    }
}

void ZoneControl::checkForMultiUpdate(QString roomId)
{
    auto room = findZoneByName(roomId);
    if(room)
        room->checkForMultiSetter();
}

void ZoneControl::handlePlaneChange(int selectedPlane)
{
    mCurrentPlane = selectedPlane;
    for(auto& zone: mRoomSettings)
    {
        if(zone->mGuiSettings.mPlane == selectedPlane)
        {
            zone->setVisibility(true);
        }
        else
        {
            zone->setVisibility(false);
        }
    }
}

RoomSetting *ZoneControl::findZoneByName(const QString &zoneName)
{
    for(auto& zone: mRoomSettings)
    {
        if(zone->mZoneName == zoneName)
        {
            return zone.get();
        }
    }
    return nullptr;
}

void ZoneControl::resetAllForMultiUpdate()
{
    for(auto& zone: mRoomSettings)
    {
        zone->unselectForMultiUpdate();
    }
}

void ZoneControl::applyMultiSetter(int value)
{
    qDebug() << "applyMultisetter with value :" <<value;
    for(auto& zone: mRoomSettings)
    {
        if(zone->isSelectedForMultiUpdate())
            zone->setSetterTemperature(value);
    }
}
