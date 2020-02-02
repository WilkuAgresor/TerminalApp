#pragma once

#include "../common/CommonDefinitions.hpp"
#include "../common/sender.hpp"

#include <heating/HeatingApp.hpp>

struct Components
{
    Components(QObject* parent, QObject* rootObject):
        mRootObject(rootObject),
        mSender(new Sender(9999, parent)),
        mHeatingApp(new HeatingApp(mRootObject, parent, this))
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

private:
    DataInitPhase mDataInitPhase = DataInitPhase::UNINITIALIZED;
    QHostAddress mMasterControllerAddress = QHostAddress(QHostAddress::SpecialAddress::Null);
    int mMasterControllerPort = -1;

    QObject* mRootObject;
    Sender* mSender;
    HeatingApp* mHeatingApp;
};
