#include <lights/LightsApp.hpp>
#include <QApplication>
#include <QGuiApplication>
#include <Components.hpp>

LightsApp::LightsApp(QObject* rootObject, QObject *parent, Components *components)
    :
      QObject(parent),
      mComponents(components),
      mRootObject(rootObject),
      mLightsView(this, mRootObject, mComponents)
{
}

void LightsApp::handleMessage(const Message &message, const QHostAddress &fromAddress, int fromPort)
{
    switch(message.getHeader().getType())
    {
    case MessageType::LIGHTS_UPDATE:
        handleReprovisionMessage(static_cast<const LightSettingsMessage&>(message), fromAddress, fromPort);
        break;
    default:
        qDebug()<< "unsupported message type in Lights subsystem";
    }
}

void LightsApp::handleReprovisionMessage(const LightSettingsMessage &message, const QHostAddress& fromAddress, int /*fromPort*/)
{
    auto payload = message.payload();
    if(mComponents->getMasterAddress().isNull())
        mComponents->setMasterAddress(fromAddress);
    if(mComponents->getMasterPort() == 0)
    {
        auto header = message.getHeader();
        if(header.mReplyPort != 0)
            mComponents->setMasterPort(header.mReplyPort);
    }

    mLightsView.handleSettingsChange(payload.mLightControllers);
}
