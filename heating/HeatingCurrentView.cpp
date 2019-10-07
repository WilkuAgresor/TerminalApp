#include <heating/HeatingCurrentView.hpp>
#include <../common/subsystems/heating/HeatingDictionary.hpp>

HeatingCurrentView::HeatingCurrentView(QObject* parent, QObject * rootView)
    : QObject(parent)
{
    mHeatingObject = rootView->findChild<QObject*>("heatingForm", Qt::FindChildOption::FindChildrenRecursively);
    mMultiSetterObject = rootView->findChild<QObject*>("heatMultiSetter", Qt::FindChildOption::FindChildrenRecursively);

    QObject::connect(mHeatingObject, SIGNAL(buttonClicked(QString)), this, SLOT(multiSelectClicked(QString)));
    QObject::connect(mHeatingObject, SIGNAL(applyMultiSetter()), this, SLOT(applyMultiSetter()));

    for(auto& roomId: sHeatingIds)
    {
        qDebug() << roomId;
        auto roomSetting = std::unique_ptr<RoomSetting>(new RoomSetting(parent, mHeatingObject, roomId));
        mRoomSettings.emplace_back(std::move(roomSetting));
    }
}

void HeatingCurrentView::setRoomCurTemp(const QString &roomId, double temperature)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setCurrentTemperature(temperature);
}

void HeatingCurrentView::setRoomSetterTemperature(const QString &roomId, quint16 setting)
{
    auto room = findRoomById(roomId);

    if(room)
        room->setSetterTemperature(setting);
}

void HeatingCurrentView::multiSelectClicked(QString roomId)
{
    qDebug() << "multisetter clicked";
    auto room = findRoomById(roomId);
    if(room)
        room->checkForMultiSetter();
}

void HeatingCurrentView::applyMultiSetter()
{
    qDebug() << "applyMultisetter";


    auto settingVariant = mMultiSetterObject->property("value");
    quint16 setting = settingVariant.toUInt();

    for(auto& room: mRoomSettings)
    {
        if(room->isCheckedForMultiSetter())
            room->setSetterTemperature(setting);
    }
}

RoomSetting *HeatingCurrentView::findRoomById(const QString &roomId)
{
    for(auto& room: mRoomSettings)
    {
        if(room->id == roomId)
        {
            return room.get();
        }
    }
    return nullptr;
}

RoomSetting::RoomSetting(QObject *parent, QObject *rootObject, QString roomId)
    :QObject(parent), id(roomId)
{
    curTempObject = rootObject->findChild<QObject*>(roomId+HEATING_CUR_TEMP, Qt::FindChildOption::FindChildrenRecursively);
    setterObject = rootObject->findChild<QObject*>(roomId+HEATING_SETTER, Qt::FindChildOption::FindChildrenRecursively);
}

void RoomSetting::setCurrentTemperature(double temp)
{
    QString text = QString().setNum(temp, 'f', 2);
    text.append('\xB0');
    text.append(" C");
    curTempObject->setProperty("text", text);

}

void RoomSetting::setSetterTemperature(quint16 setTemp)
{
    setterObject->setProperty("value", setTemp);
}

quint16 RoomSetting::getSetterTemperature()
{
    return setterObject->property("value").toUInt();
}

void RoomSetting::checkForMultiSetter()
{
    mIsCheckedForMultiSetter = !mIsCheckedForMultiSetter;
}

bool RoomSetting::isCheckedForMultiSetter()
{
    return mIsCheckedForMultiSetter;
}

HeatingProfile::HeatingProfile(QObject *parent, QObject *rootObject)
    :QObject(parent)
{
    profileObject = rootObject->findChild<QObject*>("heatModeSetter", Qt::FindChildOption::FindChildrenRecursively);
}

HeatingProfileType HeatingProfile::getCurrentProfile()
{
    return static_cast<HeatingProfileType>(profileObject->property("currentIndex").toUInt());
}

void HeatingProfile::setCurrentProfile(HeatingProfileType profile)
{

    qDebug() << "current prifile before: "<< static_cast<quint16>(getCurrentProfile());

    if(profileObject)
        profileObject->setProperty("currentIndex", static_cast<quint16>(profile));
    else
        qDebug() << "not found heating profile";


    qDebug() << "current prifile after: "<< static_cast<quint16>(getCurrentProfile());
}
