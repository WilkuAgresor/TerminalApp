#pragma once

#include <QObject>
#include <../common/subsystems/heating/HeatingRetrieveStatistics.hpp>
#include <mutex>

class Components;

class HeatingStatistics : public QObject
{
    Q_OBJECT

public:
    HeatingStatistics(QObject* parent, QObject* rootView, Components* components);

    void addZone(const QString& zoneName);

    void addLine(const QString& zoneName, TemperatureSensorType sensorType);
    void removeLine(const QString& zoneName, TemperatureSensorType sensorType);

    void addPoint(const QString& zoneName, TemperatureSensorType sensorType, const TemperatureSensorDataEntry& data);

    void clear();

public slots:
    void handleZoneChecked(QString zoneName, int sensorType, int periodType);

private:

    QString formatLineName(const QString& zoneName, TemperatureSensorType sensorType);

    Components* mComponents;
    QObject* mStatChartObject;
};
