#include "VoiceCom.hpp"
#include <QDebug>

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
    mRisipAccConfig->setLocalPort(5060);

    mAccount = risip::Risip::instance()->createAccount(mRisipAccConfig);

    risip::Risip::instance()->setDefaultAccount(uri);

    mAccount->login();

    auto callManager = risip::RisipCallManager::instance();
    callManager->setActiveAccount(mAccount);


    QObject::connect(callManager, SIGNAL(incomingCall(risip::RisipCall*)), this, SLOT(incomingCall(risip::RisipCall*)));


    risip::Risip::instance()->accessPhoneMedia();
}

void VoiceCom::incomingCall(risip::RisipCall* call)
{
    qDebug() << "INCOMING CALL SLOT";
    call->answer();
}
