#include <MainApp.hpp>

#include <chrono>
#include <thread>

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Main Application Constructor";
}

MainApplication::~MainApplication()
{
}

void MainApplication::initiate(QObject *rootObject)
{
    mRootObject = rootObject;
    mComponents = new Components(parent(), rootObject);
    mReceiver = new TerminalReceiver(parent(), mComponents->getNetworkPortRepository(), *mComponents);
    mComponents->getVoiceCom().initiate();
    mMonitoringApp = new MonitoringApp(parent(), mComponents, rootObject);


    //initiate additional threads
    QThreadPool::globalInstance()->start(mMonitoringApp);
}
