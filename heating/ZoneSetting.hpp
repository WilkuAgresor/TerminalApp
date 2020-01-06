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
    RoomSetting(QObject* parent, QObject* rootObject, QString roomId, int setTemp, bool isOn);
    ~RoomSetting() = default;

    void setCurrentTemperature(double temp);
    void setSetterTemperature(quint16 setTemp);
    quint16 getSetterTemperature();

    void checkForMultiSetter();
    void selectForMultiUpdate();
    void unselectForMultiUpdate();
    bool isSelectedForMultiUpdate();

    HeatZoneSetting getZoneSetting();


    bool operator==(const RoomSetting &q) {return id==q.id;}

    QObject* mHeatingObject;
    QObject* mFrontObject;

    QString id;
    quint16 mSetTemperature = 2200;
    bool mIsOn;

    bool mIsSelectedForMultiUpdate = false;

public slots:
    void handleSelectedForMultiUpdate();
    void handleSetValueChanged(int newValue);
    void handleSwitchedOnOff(bool value);

private:
    QString formatTemperature(double temp);
};
