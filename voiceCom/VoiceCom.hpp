#pragma once
#include <QObject>

//#include <risip.h>
//#include <risipcallmanager.h>
//#include <risipcall.h>

class VoiceCom : public QObject
{
    Q_OBJECT
public:
    VoiceCom(QObject* parent);
    ~VoiceCom();

    void initiate();

public slots:
    void incomingCall(/*risip::RisipCall *call*/);


private:
//    risip::RisipEndpoint mRisipEndpoint;
//    risip::RisipAccountConfiguration* mRisipAccConfig;
//    risip::RisipAccount* mAccount;
};

