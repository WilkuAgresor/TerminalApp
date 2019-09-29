#pragma once

#include <QString>
#include <QObject>
#include <QDebug>

#include <vector>
#include <memory>

class RoomSetting : public QObject
{
public:
    RoomSetting(QObject*parent, QString roomId);
    ~RoomSetting() = default;

    void setCurrentTemperature(double temp);

    void setSetterTemperature(quint16 setTemp);

    void checkForMultiSetter();
    bool isCheckedForMultiSetter();

    bool operator==(const RoomSetting &q) {return id==q.id;}

    QObject* curTempObject;
    QObject* setterObject;

    bool mIsCheckedForMultiSetter = false;
    QString id;
};

class Heating : public QObject
{
    Q_OBJECT

public:
    Heating(QObject *rootView);
    ~Heating() = default;

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
