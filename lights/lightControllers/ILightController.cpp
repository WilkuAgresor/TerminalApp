#include "ILightController.hpp"
#include <QtConcurrent/QtConcurrent>
#include <../common/messages/replyMessage.hpp>
#include <Components.hpp>


ILightController::ILightController(QObject* parent, QObject *lightsView, Components* components, const LightControllerSettings& settings)
    : QObject(parent),
      mLightsViewObject(lightsView),
      mComponents(components),
      mControllerSettings(settings)
{
}

ILightController::~ILightController()
{

}

LightControllerType ILightController::getType()
{
    return mControllerSettings.mType;
}

int ILightController::getId()
{
    return mControllerSettings.mId;
}

QString ILightController::getName()
{
    return mControllerSettings.mName;
}

bool ILightController::getIsOn()
{
    return mControllerSettings.mIsOn;
}

int ILightController::getDimm()
{
    return mControllerSettings.mDimm;
}

QString ILightController::getColor()
{
    return mControllerSettings.mColor;
}

LightControllerGuiSettings ILightController::getGuiSettings()
{
    return mControllerSettings.mGuiSettings;
}

LightControllerSettings ILightController::getControllerSettings()
{
    return mControllerSettings;
}

void ILightController::handlePlaneChange(int selectedPlane)
{
    if(mControllerObject)
    {
        auto shouldBeVisible = (selectedPlane == getGuiSettings().mPlane);
        QMetaObject::invokeMethod(mControllerObject, "setVisible", Qt::DirectConnection,
                                  Q_ARG(QVariant, QVariant(shouldBeVisible)));
    }
}

void ILightController::handleSettingsChangeFromController(const LightControllerSettings &settings)
{
    qDebug() << "settings 0";

    //gui changes
    if(settings.mGuiSettingsChanged)
    {
        const auto& newSettings = settings.mGuiSettings;
        auto& oldSettings = mControllerSettings.mGuiSettings;

        if(mLightsViewObject)
        {
            mLightsViewObject->setProperty("lightControllerX", QVariant(newSettings.mX));
            mLightsViewObject->setProperty("lightsControllerY", QVariant(newSettings.mY));
        }
        oldSettings.mX = newSettings.mX;
        oldSettings.mY = newSettings.mY;
        oldSettings.mPlane = newSettings.mPlane;
    }
}

void ILightController::commitChangedSettings(const LightControllerSettings& settings)
{
    LightSettingsPayload payload;
    payload.mLightControllers.push_back(settings);
    LightSettingsMessage message(payload);

    qDebug() << "sending request: "<<payload.toString();

    mComponents->getSender().send(mComponents->getMasterAddress(), mComponents->getMasterPort(), message.toData());

//    QtConcurrent::run([this, settings]{
//        qDebug() << "save current settings to the DB";

//        LightSettingsPayload payload;
//        payload.mLightControllers.push_back(settings);

//        LightSettingsMessage message(payload);
//        try {

//        auto response = mComponents->getSender().sendReceive(mComponents->getMasterAddress(), mComponents->getMasterPort(), message);

//        if(response.size() == 0)
//        {
//            qDebug() << "NO RESPONSE";
//            ongoingUpdates--;
//            return;
//        }
//        Message msg(response);
//        auto header = msg.getHeader();
//        if(header.getType() == MessageType::REPLY)
//        {
//            auto& respMsg = static_cast<ReplyMessage&>(msg);
//            auto payload = respMsg.payload();
//            if(payload.mStatus == Status::OK)
//            {
//                qDebug() << "configuration applied successfully";
//            }
//            else
//            {
//                qDebug() << "configuration not applied";
//            }
//        }
//        } catch (const std::exception& ex) {
//            qDebug() << "exception: "<<ex.what();
//        }
//        ongoingUpdates--;
//      });
}

