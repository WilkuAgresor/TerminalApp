#include <MainApp.hpp>

#include <chrono>
#include <thread>

#include <risip.h>
#include <risipcallmanager.h>

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{
    qDebug() << "Main Application Constructor";
}

MainApplication::~MainApplication()
{
    mRisipEndpoint.stop();
}

void MainApplication::initiate(QObject *rootObject)
{
    mRootObject = rootObject;
    mComponents = new Components(parent(), rootObject);
    mReceiver = new TerminalReceiver(parent(), mComponents->getNetworkPortRepository(), *mComponents);

    mRisipEndpoint.start();
    mRisipAccConfig = new risip::RisipAccountConfiguration(this);

    QString uri = "sip:terminal_pietro@192.168.0.150:5060";
    mRisipAccConfig->setUri(uri);
    mRisipAccConfig->setUserName("terminal_pietro");
    mRisipAccConfig->setPassword("4444");
    mRisipAccConfig->setServerAddress("192.168.0.150:5060");
    mRisipAccConfig->setLocalPort(5060);

    mAccount = risip::Risip::instance()->createAccount(mRisipAccConfig);

    risip::Risip::instance()->setDefaultAccount(uri);

    mAccount->login();

    risip::RisipCallManager::instance()->setActiveAccount(mAccount);

    risip::Risip::instance()->accessPhoneMedia();
}
