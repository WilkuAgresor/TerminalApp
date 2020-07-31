#pragma once
#include <heating/zoneSettings/ZoneSetting.hpp>

#include <QString>
#include <QObject>
#include <QDebug>
#include <vector>
#include <memory>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <../common/subsystems/heating/HeatingZoneSettings.hpp>

class ZoneControl: public QObject
{
    Q_OBJECT
public:
    ZoneControl(QObject* setWidget, QObject* curTempWidget , QObject* parent);

    void clearZones();

    void addOrUpdateZoneSetting(const std::vector<HeatZoneSetting>& settings);
    void addOrUpdateZoneSetting(const HeatZoneSetting& setting);

    HeatZoneSetting getZoneSetting(const QString& id);
    std::vector<HeatZoneSetting> getAllZoneSettings();

    void setAllForMultiUpdate();
    void resetAllForMultiUpdate();
    void applyMultiSetter(int value);
    void checkForMultiUpdate(QString roomId);
    void handlePlaneChange(int selectedPlane);
private:
    RoomSetting *findZoneByName(const QString& zoneName);
    void addZoneSettingObject(const HeatZoneSetting& setting);
//    void setRoomCurTemp(const QString &roomId, double temperature);
//    void setRoomSetterTemperature(const QString &roomId, quint16 setting);

    std::vector<std::unique_ptr<RoomSetting>> mRoomSettings;

    QObject* mSetWidgetPtr;
    QObject* mCurTempWidgetPtr;
    int mCurrentPlane = 0;
};

