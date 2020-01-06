#include <heating/HeatingApp.hpp>
#include <QApplication>
#include <QGuiApplication>
#include <Components.hpp>

HeatingApp::HeatingApp(QObject* rootObject, QObject *parent, Components *components)
    :
      QObject(parent),
      mComponents(components),
      mRootObject(rootObject),
      mCurrentView(new HeatingCurrentView(parent, rootObject, mComponents))
{
}

void HeatingApp::handleMessage(const Message &message, const QHostAddress &fromAddress, int fromPort)
{
    switch(message.getHeader().getType())
    {
    case MessageType::HEAT_SETTINGS_UPDATE:
        handleReprovisionMessage(static_cast<const HeatSettingsMessage&>(message), fromAddress, fromPort);
        // handleStatusUpdateMessage(static_cast<const HeatStatusMessage&>(message));
        break;
    default:
        qDebug()<< "unsupported message type in HEATING subsystem";
    }
}

void HeatingApp::handleReprovisionMessage(const HeatSettingsMessage &message, const QHostAddress& fromAddress, int fromPort)
{
    auto payload = message.payload();
    mComponents->setMasterAddress(fromAddress);
    mComponents->setMasterPort(fromPort);
    mCurrentView->setProfileList(payload.mProfiles);
    for(auto& zoneSetting: payload.mZoneSettings)
        mCurrentView->addZoneSettingObject(zoneSetting);
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
