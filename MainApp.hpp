#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include <mutex>
#include <QQmlContext>

#include <../common/sender.hpp>
#include <../common/receiver/receiver.hpp>
#include <../common/CommonDefinitions.hpp>

#include <Components.hpp>
#include <Receiver.hpp>
#include <monitoring/MonitoringApp.hpp>
#include <proximitySensor/ProximityMonitor.hpp>
#include <healthcheck/HealthCheck.hpp>

class MainApplication : public QObject
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = nullptr);
    ~MainApplication();

    void initiate(QObject* rootObject, QQmlContext* context);

private:
    QQmlContext* mQmlContext;
    QObject* mRootObject;
    Components* mComponents;
    TerminalReceiver* mReceiver;
    MonitoringApp* mMonitoringApp;
    ProximityMonitor* mProximityMonitor;
    HealthCheck* mHealthCheck;
};
