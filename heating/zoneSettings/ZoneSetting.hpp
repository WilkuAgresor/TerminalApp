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
    RoomSetting(QObject* parent, QObject* setWidget, QObject* curWidget, QString roomId, int setTemp, bool isOn, const HeatZoneGuiSettings& guiSettings);
    ~RoomSetting() = default;

    void setCurrentTemperature(quint16 temp);
    void setSetterTemperature(quint16 setTemp);
    quint16 getSetterTemperature();
    quint16 getCurrentTemperature();

    void checkForMultiSetter();
    void selectForMultiUpdate();
    void unselectForMultiUpdate();
    bool isSelectedForMultiUpdate();

    HeatZoneSetting getZoneSetting();
    void updateZoneSetting(const HeatZoneSetting &setting);

    void setVisibility(bool isVisible);


    bool operator==(const RoomSetting &q) {return id==q.id;}

    QObject* mSetterWidget;
    QObject* mZoneSetObject;
    QObject* mZoneCurObject;
    bool mZoneCurVisibility = false;

    QObject* mCurWidget;

    QString id;
    quint16 mSetTemperature = 2200;
    quint16 mCurTemperature = 2200;

    bool mIsOn;
    HeatZoneGuiSettings mGuiSettings;

    bool mIsSelectedForMultiUpdate = false;

    void setIsOn(bool value);
public slots:
    void handleSelectedForMultiUpdate();
    void handleSetValueChanged(int newValue);
    void handleSwitchedOnOff(bool value);

private:
    QString formatTemperature(quint16 temp);
};
