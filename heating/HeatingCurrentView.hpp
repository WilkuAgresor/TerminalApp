#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QComboBox>

#include <vector>
#include <memory>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <heating/zoneSettings/ZoneControl.hpp>
#include <../common/subsystems/heating/HeatingZoneSettings.hpp>

struct Components;

class HeatingCurrentView : public QObject
{
    Q_OBJECT

public:
    HeatingCurrentView(QObject *parent, QObject *rootView, Components* components);
    ~HeatingCurrentView() = default;

    void setCurrentHeatingProfile(int id);

    void setProfileList(const std::vector<HeatProfile>& profiles);

    void setBusy(bool value);

    void setHeatZoneSettings(const std::vector<HeatZoneSetting> &settings);
    int getCurrentProfileId();
public slots:
    void multiSelectClicked(QString roomId);
    void applyMultiSetter(int value);
    void setAllForMultiUpdate();
    void resetAllForMultiUpdate();
    void saveCurrentSettings();
    void resetCurrentSettings();
    void handleProfileSelection(int profileId);
    void handlePlaneChange(int selectedPlane);

private:
    ZoneControl* mZoneFrontControl;

    QObject* mSetterObject;
    QObject* mCurrentObject;
    int mCurrentHeatingProfile = 0;
    bool mMasterOn = true;
    Components* mComponents;

};
