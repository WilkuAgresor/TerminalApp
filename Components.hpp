#pragma once

#include "../common/CommonDefinitions.hpp"
#include "../common/sender.hpp"

#include <heating/HeatingApp.hpp>

struct Components
{
    Components(QObject* parent, QObject* rootObject):
        mRootObject(rootObject),
        mSender(new Sender(9999, parent)),
        mHeatingApp(new HeatingApp(mRootObject, parent))
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

private:
    QObject* mRootObject;
    Sender* mSender;
    HeatingApp* mHeatingApp;
};
