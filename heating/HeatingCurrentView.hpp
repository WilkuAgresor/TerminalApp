#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QComboBox>

#include <vector>
#include <memory>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <heating/ZoneSetting.hpp>
#include <../common/subsystems/heating/HeatingZoneSettings.hpp>

class Components;

class HeatingCurrentView : public QObject
{
    Q_OBJECT

public:
    HeatingCurrentView(QObject *parent, QObject *rootView, Components* components);
    ~HeatingCurrentView() = default;

    void setRoomCurTemp(const QString& roomId, double temperature);

    void setRoomSetterTemperature(const QString& roomId, quint16 setting);
    void setCurrentHeatingProfile(int id);

    void addZoneSettingObject(const HeatZoneSetting& setting);
    void setProfileList(const std::vector<HeatProfile>& profiles);

    void setBusy(bool value);

public slots:
    void multiSelectClicked(QString roomId);
    void applyMultiSetter(int value);
    void setAllForMultiUpdate();
    void resetAllForMultiUpdate();
    void saveCurrentSettings();
    void resetCurrentSettings();
    void handleProfileSelection(int profileId);

private:
    RoomSetting *findRoomById(const QString& roomId);
    QObject* mSetterObject;
    int mCurrentHeatingProfile = 0;
    bool mMasterOn = true;
    Components* mComponents;

    std::vector<std::unique_ptr<RoomSetting>> mRoomSettings;
};
