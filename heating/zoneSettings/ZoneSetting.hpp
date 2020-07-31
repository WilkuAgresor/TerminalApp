#pragma once

#include <QString>
#include <QObject>
#include <QDebug>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <../common/subsystems/heating/HeatingZoneSettings.hpp>

class RoomSetting : public QObject
{
    Q_OBJECT
public:
    RoomSetting(QObject* parent, QObject* setWidget, QObject* curWidget, QString zoneName, int zoneId, int curTemp, int setTemp, bool isOn, const HeatZoneGuiSettings& guiSettings);
    ~RoomSetting() = default;

    void setCurrentTemperature(qint16 temp);
    void setSetterTemperature(qint16 setTemp);
    qint16 getSetterTemperature();
    qint16 getCurrentTemperature();

    void checkForMultiSetter();
    void selectForMultiUpdate();
    void unselectForMultiUpdate();
    bool isSelectedForMultiUpdate();

    HeatZoneSetting getZoneSetting();
    void updateZoneSetting(const HeatZoneSetting &setting);

    void setVisibility(bool isVisible);


    bool operator==(const RoomSetting &q) {return mZoneName==q.mZoneName;}

    QObject* mSetterWidget;
    QObject* mZoneSetObject;
    QObject* mZoneCurObject;
    bool mZoneCurVisibility = false;

    QObject* mCurWidget;

    QString mZoneName;
    int mZoneId;
    qint16 mCurTemperature = TEMPERATURE_INVALID;
    qint16 mSetTemperature = TEMPERATURE_INVALID;

    bool mIsOn;
    HeatZoneGuiSettings mGuiSettings;

    bool mIsSelectedForMultiUpdate = false;

    void setIsOn(bool value);
public slots:
    void handleSelectedForMultiUpdate();
    void handleSetValueChanged(int newValue);
    void handleSwitchedOnOff(bool value);
};
