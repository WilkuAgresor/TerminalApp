#include <heating/HeatingApp.hpp>
#include <QApplication>
#include <QGuiApplication>
#include <Components.hpp>

HeatingApp::HeatingApp(QObject* rootObject, QObject *parent, Components *components)
    :
      QObject(parent),
      mComponents(components),
      mRootObject(rootObject),
      mCurrentView(new HeatingCurrentView(parent, rootObject, mComponents)),
      mStatistics(new HeatingStatistics(parent, rootObject, mComponents)),
      mBoilerSettings(new HeatingBoilerSettings(parent, rootObject, mComponents))
{
}

void HeatingApp::handleMessage(const Message &message, const QHostAddress &fromAddress)
{
    switch(message.getHeader().getType())
    {
    case MessageType::HEAT_SETTINGS_UPDATE:
        handleReprovisionMessage(static_cast<const HeatSettingsMessage&>(message), fromAddress);
        // handleStatusUpdateMessage(static_cast<const HeatStatusMessage&>(message));
        break;

    case MessageType::BOILER_SETTINGS:
        mBoilerSettings->handleSettingsMessage(static_cast<const BoilerSettingsMessage&>(message));

        break;
    default:
        qDebug()<< "unsupported message type in HEATING subsystem";
        break;
    }
}

void HeatingApp::handleReprovisionMessage(const HeatSettingsMessage &message, const QHostAddress& fromAddress)
{
    auto payload = message.payload();
    if(mComponents->getMasterAddress().isNull())
        mComponents->setMasterAddress(fromAddress);
    if(mComponents->getMasterPort() == -1)
    {        
        mStatistics->clear();

        auto header = message.getHeader();
        if(header.mReplyPort != 0)
            mComponents->setMasterPort(header.mReplyPort);
    }

    for(auto& zone: payload.mZoneSettings)
    {
        mStatistics->addZone(zone.mZoneName);
    }

    if(payload.mProfiles.size() > 1)
        mCurrentView->setProfileList(payload.mProfiles);

    //update dla konkretnego profilu
    //procesować tylko jeżeli jest to aktualnie wyświetlany profil
    if(payload.mProfiles.size() == 1)
    {
        if(payload.mProfiles.at(0).mId == mCurrentView->getCurrentProfileId()+1)
            mCurrentView->setHeatZoneSettings(payload.mZoneSettings);
    }
    else if(!payload.mZoneSettings.empty())
    {
        mCurrentView->setHeatZoneSettings(payload.mZoneSettings);
    }

    mCurrentView->setBusy(false);
}

//void HeatingApp::handleStatusUpdateMessage(const HeatStatusMessage &message)
//{
//    auto payload = message.payload();

//    qDebug() << "heating status update message";
//    for(auto& status: payload.mZoneSettings)
//    {
//        double temperature = status.mSetTemperature;
//        temperature /= 100; //set 2 digit precision
//        mCurrentView->setRoomCurTemp(status.mZoneId, temperature);
//    }
//    //mHeatingProfile->setCurrentProfile(payload.mCurrentProfile);
//}
