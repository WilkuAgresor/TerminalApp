#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QComboBox>

#include <vector>
#include <memory>

#include <../common/subsystems/heating/HeatingDictionary.hpp>

class RoomSetting : public QObject
{
public:
    RoomSetting(QObject* parent, QObject* rootObject, QString roomId);
    ~RoomSetting() = default;

    void setCurrentTemperature(double temp);
    void setSetterTemperature(quint16 setTemp);
    quint16 getSetterTemperature();

    void checkForMultiSetter();
    bool isCheckedForMultiSetter();

    bool operator==(const RoomSetting &q) {return id==q.id;}

    QObject* curTempObject;
    QObject* setterObject;

    bool mIsCheckedForMultiSetter = false;
    QString id;
};

class HeatingProfile: public QObject
{
public:
    HeatingProfile(QObject* parent, QObject* rootObject);
    ~HeatingProfile() = default;

    HeatingProfileType getCurrentProfile();
    void setCurrentProfile(HeatingProfileType profile);
private:
    QObject* profileObject;
};

class HeatingCurrentView : public QObject
{
    Q_OBJECT

public:
    HeatingCurrentView(QObject *parent, QObject *rootView);
    ~HeatingCurrentView() = default;

    void setRoomCurTemp(const QString& roomId, double temperature);

    void setRoomSetterTemperature(const QString& roomId, quint16 setting);

public slots:
    void multiSelectClicked(QString roomId);
    void applyMultiSetter();

private:
    RoomSetting *findRoomById(const QString& roomId);

    std::vector<std::unique_ptr<RoomSetting>> mRoomSettings;
    QObject* mHeatingObject;
    QObject* mMultiSetterObject;

};
