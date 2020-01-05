#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QComboBox>

#include <vector>
#include <memory>

#include <../common/subsystems/heating/HeatingDictionary.hpp>
#include <heating/ZoneSetting.hpp>

class HeatingProfile: public QObject
{
public:
    HeatingProfile(QObject* parent, QObject* rootObject);
    ~HeatingProfile() = default;

//    HeatingProfileType getCurrentProfile();
//    void setCurrentProfile(HeatingProfileType profile);
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
    void setCurrentHeatingProfile(int id);

public slots:
    void multiSelectClicked(QString roomId);
    void applyMultiSetter(int value);
    void setAllForMultiUpdate();
    void resetAllForMultiUpdate();
    void saveCurrentSettings();
    void resetCurrentSettings();


private:
    RoomSetting *findRoomById(const QString& roomId);
    QObject* mSetterObject;
    int mCurrentHeatingProfile = 0;

    std::vector<std::unique_ptr<RoomSetting>> mRoomSettings;
};
