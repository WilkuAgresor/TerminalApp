#include <MainApp.hpp>

#include <chrono>
#include <thread>
#include <pigpio.h>

#include <QQmlContext>

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Main Application Constructor";
}

MainApplication::~MainApplication()
{
    gpioTerminate();
}

void MainApplication::initiate(QObject *rootObject, QQmlContext* context)
{
    gpioCfgClock(5, 0, 0);
    int status = gpioInitialise();
    qDebug() << "GPIO initialize: "<<(status == PI_INIT_FAILED ? "Failure" : "Success");

    mQmlContext = context;
    mRootObject = rootObject;
    mComponents = new Components(parent(), rootObject, context);
    mReceiver = new TerminalReceiver(parent(), mComponents->getNetworkPortRepository(), *mComponents);
    mComponents->getVoiceCom().initiate();
    mMonitoringApp = new MonitoringApp(parent(), mComponents, rootObject);
    mProximityMonitor = new ProximityMonitor(parent(), mComponents);
    mHealthCheck = new HealthCheck(parent(), mComponents);

    //initiate additional threads
    QThreadPool::globalInstance()->start(mMonitoringApp);
    QThreadPool::globalInstance()->start(mProximityMonitor);
    QThreadPool::globalInstance()->start(mHealthCheck);
}
