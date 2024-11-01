#pragma once

#include "../common/CommonDefinitions.hpp"
#include "../common/sender.hpp"

#include <QQmlContext>

#include <heating/HeatingApp.hpp>
#include <lights/LightsApp.hpp>
#include <voiceCom/VoiceCom.hpp>

struct Components
{
    Components(QObject* parent, QObject* rootObject, QQmlContext* context):
        mQmlContext(context),
        mRootObject(rootObject),
        mSender(new Sender(9999, mNetworkPortRepository, parent)),
        mHeatingApp(new HeatingApp(mRootObject, parent, this)),
        mLightsApp(new LightsApp(mRootObject, parent, this)),
        mVoiceCom(new VoiceCom(parent))
    {
    }

    Sender& getSender()
    {
        return *mSender;
    }

    HeatingApp& getHeatingApp()
    {
        return *mHeatingApp;
    }

    LightsApp& getLightsApp()
    {
        return *mLightsApp;
    }

    DataInitPhase getDataInitPhase() const
    {
        return mDataInitPhase;
    }

    void setDataInitPhase(DataInitPhase value)
    {
        mDataInitPhase = value;
    }

    QHostAddress getMasterAddress()
    {
        return mMasterControllerAddress;
    }
    void setMasterAddress(const QHostAddress& masterAddress)
    {
        mMasterControllerAddress = masterAddress;
    }
    void setMasterPort(int masterPort)
    {
        mMasterControllerPort = masterPort;
    }
    int getMasterPort()
    {
        return mMasterControllerPort;
    }
    ReceivePortsBank& getNetworkPortRepository()
    {
        return mNetworkPortRepository;
    }
    VoiceCom& getVoiceCom()
    {
        return *mVoiceCom;
    }

    QQmlContext* getQmlContext()
    {
        return mQmlContext;
    }

private:
    DataInitPhase mDataInitPhase = DataInitPhase::UNINITIALIZED;
    QHostAddress mMasterControllerAddress = QHostAddress(QHostAddress::SpecialAddress::Null);
    int mMasterControllerPort = -1;

    QQmlContext* mQmlContext;
    ReceivePortsBank mNetworkPortRepository;
    QObject* mRootObject;
    Sender* mSender;
    HeatingApp* mHeatingApp;
    LightsApp* mLightsApp;
    VoiceCom* mVoiceCom;

};
