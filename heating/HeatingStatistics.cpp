#include "HeatingStatistics.hpp"
#include <Components.hpp>
#include <QtCharts/QChartView>
#include <QtCharts>

HeatingStatistics::HeatingStatistics(QObject* parent, QObject* rootView, Components *components)
    : QObject(parent), mComponents(components)
{
    mStatChartObject = rootView->findChild<QObject*>("heatingStatistics", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mStatChartObject, SIGNAL(zoneChecked(QString, int, int)), this, SLOT(handleZoneChecked(QString, int, int)));

//    QMetaObject::invokeMethod(mStatChartObject, "addLine", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line1")));

//    QMetaObject::invokeMethod(mStatChartObject, "addLine", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line2")));

//    QMetaObject::invokeMethod(mStatChartObject, "addLine", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line3")));

//    auto date = QDateTime::fromString("2020-07-18T12:56:35", Qt::ISODate);
//    auto date2 = QDateTime::fromString("2020-07-19T00:57:35", Qt::ISODate);
//    auto date3 = QDateTime::fromString("2020-07-19T10:58:35", Qt::ISODate);

//    QMetaObject::invokeMethod(mStatChartObject, "addPoint", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line3")),
//                              Q_ARG(QVariant, QVariant(date.toMSecsSinceEpoch())),
//                              Q_ARG(QVariant, QVariant("23")));

//    QMetaObject::invokeMethod(mStatChartObject, "addPoint", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line3")),
//                              Q_ARG(QVariant, QVariant(date2.toMSecsSinceEpoch())),
//                              Q_ARG(QVariant, QVariant("25")));

//    QMetaObject::invokeMethod(mStatChartObject, "addPoint", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line3")),
//                              Q_ARG(QVariant, QVariant(date3.toMSecsSinceEpoch())),
//                              Q_ARG(QVariant, QVariant("20")));

//    QMetaObject::invokeMethod(mStatChartObject, "removeLines", Qt::DirectConnection);
//    QMetaObject::invokeMethod(mStatChartObject, "removeLine", Qt::DirectConnection,
//                              Q_ARG(QVariant, QVariant("line1")));

}

void HeatingStatistics::addZone(const QString &zoneName)
{
    QMetaObject::invokeMethod(mStatChartObject, "addZone", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(zoneName)));
}

void HeatingStatistics::addLine(const QString &zoneName, TemperatureSensorType sensorType)
{
    QMetaObject::invokeMethod(mStatChartObject, "addLine", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(formatLineName(zoneName, sensorType))));
}

void HeatingStatistics::removeLine(const QString &zoneName, TemperatureSensorType sensorType)
{
    QMetaObject::invokeMethod(mStatChartObject, "removeLine", Qt::DirectConnection,
                              Q_ARG(QVariant, QVariant(formatLineName(zoneName, sensorType))));
}

void HeatingStatistics::addPoint(const QString &zoneName, TemperatureSensorType sensorType, const TemperatureSensorDataEntry &data)
{
    auto date = QDateTime::fromString(data.mTimestamp, Qt::ISODate);

    double dTemp = static_cast<double>(data.mValue)/100;

    QMetaObject::invokeMethod(mStatChartObject, "addPoint", Qt::QueuedConnection,
                              Q_ARG(QVariant, QVariant(formatLineName(zoneName, sensorType))),
                              Q_ARG(QVariant, QVariant(date.toMSecsSinceEpoch())),
                              Q_ARG(QVariant, QVariant(dTemp)));
}

void HeatingStatistics::clear()
{
    QMetaObject::invokeMethod(mStatChartObject, "removeLines", Qt::DirectConnection);
    QMetaObject::invokeMethod(mStatChartObject, "removeZones", Qt::DirectConnection);
}

void HeatingStatistics::handleZoneChecked(QString zoneName, int sensorType, int periodType)
{
    auto sensor = static_cast<TemperatureSensorType>(sensorType);
    HeatRetrieveStatisticsPayload payload (zoneName, sensor, static_cast<TemperatureStatisticsTimeScope>(periodType));

    HeatRetrieveStatisticsMessage message(payload);

    auto response = mComponents->getSender().sendReceive(mComponents->getMasterAddress(), mComponents->getMasterPort(), message, 30000);
    Message msg(response);
    auto header = msg.getHeader();
    if(header.getType() == MessageType::HEAT_STATISTICS_RESPONSE)
    {
        auto& respMsg = static_cast<HeatRetrieveStatisticsResponse&>(msg);
        auto respPayload = respMsg.payload();

        if(respPayload.mEntries.empty())
        {
            return;
        }

        addLine(zoneName, sensor);

        for(const auto& point: respPayload.mEntries)
        {
            addPoint(zoneName, sensor, point);
        }
    }
}

QString HeatingStatistics::formatLineName(const QString &zoneName, TemperatureSensorType sensorType)
{
    auto lineName = zoneName;
    lineName.append(".");
    lineName.append(QString::number(static_cast<int>(sensorType)));
    return  lineName;
}
