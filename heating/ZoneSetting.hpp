#pragma once

#include <QString>
#include <QObject>
#include <QDebug>

#include <../common/subsystems/heating/HeatingDictionary.hpp>

class RoomSetting : public QObject
{
    Q_OBJECT
public:
    RoomSetting(QObject* parent, QObject* rootObject, QString roomId);
    ~RoomSetting() = default;

    void setCurrentTemperature(double temp);
    void setSetterTemperature(quint16 setTemp);
    quint16 getSetterTemperature();

    void checkForMultiSetter();
    void selectForMultiUpdate();
    void unselectForMultiUpdate();
    bool isSelectedForMultiUpdate();

    bool operator==(const RoomSetting &q) {return id==q.id;}

    QObject* mHeatingObject;
    QObject* mFrontObject;

    QString id;
    quint16 mSetTemperature = 2200;

    bool mIsSelectedForMultiUpdate = false;

public slots:
    void handleSelectedForMultiUpdate();
    void handleSetValueChanged(int newValue);

private:
    QString formatTemperature(double temp);
};
