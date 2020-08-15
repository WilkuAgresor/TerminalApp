#include <MainApp.hpp>

#include <chrono>
#include <thread>

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Main Application Constructor";
}

void MainApplication::initiate(QObject *rootObject)
{
    mRootObject = rootObject;
    mComponents = new Components(parent(), rootObject);
    mReceiver = new TerminalReceiver(parent(), mComponents->getNetworkPortRepository(), *mComponents);
}




