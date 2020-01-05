#include <heating/HeatingApp.hpp>
#include <QApplication>
#include <QGuiApplication>


HeatingApp::HeatingApp(QObject* rootObject, QObject *parent)
    :
      QObject(parent),
      mRootObject(rootObject),
      mCurrentView(new HeatingCurrentView(parent, rootObject)),
      mHeatingProfile(new HeatingProfile(parent, rootObject))
{
}

void HeatingApp::handleMessage(const Message &message)
{
    switch(message.getHeader().getType())
    {
    case MessageType::HEAT_STATUS_UPDATE:
        qDebug() << "status message: "<<message.toString();
       // handleStatusUpdateMessage(static_cast<const HeatStatusMessage&>(message));
        break;
    default:
        qDebug()<< "unsupported message type in HEATING subsystem";
    }
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
