#include "VoiceCom.hpp"
#include <QDebug>

#include <risipratemanager.h>

#include <chrono>
#include <thread>

VoiceCom::VoiceCom(QObject *parent)
 : QObject(parent)
{
}

VoiceCom::~VoiceCom()
{
    mAccount->logout();
    mRisipEndpoint.stop();
}

void VoiceCom::initiate()
{
    mRisipEndpoint.start();

    mRisipAccConfig = new risip::RisipAccountConfiguration(this);

    QString uri = "sip:terminal_pietro@192.168.0.150:5060";
    mRisipAccConfig->setUri(uri);
    mRisipAccConfig->setUserName("terminal_pietro");
    mRisipAccConfig->setPassword("4444");
    mRisipAccConfig->setServerAddress("192.168.0.150:5060");

    mAccount = risip::Risip::instance()->createAccount(mRisipAccConfig);

    risip::Risip::instance()->setDefaultAccount(uri);

    mAccount->login();

    auto callManager = risip::RisipCallManager::instance();
    callManager->setActiveAccount(mAccount);

    QObject::connect(callManager, SIGNAL(incomingCall(risip::RisipCall*)), this, SLOT(incomingCall(risip::RisipCall*)), Qt::QueuedConnection);
}

void VoiceCom::incomingCall(risip::RisipCall* call)
{
    qDebug() << "INCOMING CALL SLOT";
    using namespace std::chrono;
    std::this_thread::sleep_for(seconds(1));

    call->answer();
}
