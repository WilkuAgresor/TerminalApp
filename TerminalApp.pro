QT += quick widgets charts multimedia core5compat multimediawidgets
CONFIG += c++20

LIBS += -lpigpio

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../common/NetworkPortPool.cpp \
    ../common/subsystems/AppBase.cpp \
    ../common/subsystems/heating/BoilerSettingsMessage.cpp \
    ../common/subsystems/heating/HeatingRetrieveMessage.cpp \
    ../common/subsystems/heating/HeatingRetrieveStatistics.cpp \
    ../common/subsystems/heating/PumpSettingsMessage.cpp \
    ../common/subsystems/schedule/ScheduleEventTypes.cpp \
    ../common/subsystems/topology/topologyMessages.cpp \
    ../common/subsystems/lights/LightControllerSettings.cpp \
    ../common/subsystems/lights/LightsRetrieveMessage.cpp \
    alarm/AlarmMainView.cpp \
    healthcheck/HealthCheck.cpp \
    heating/HeatingBoilerSettings.cpp \
    heating/HeatingCommon.cpp \
    heating/HeatingStatistics.cpp \
    heating/zoneSettings/ZoneControl.cpp \
    heating/zoneSettings/ZoneSetting.cpp \
    lights/LightsApp.cpp \
    lights/LightsView.cpp \
    lights/lightControllers/ColorLightController.cpp \
    lights/lightControllers/DimmableLightController.cpp \
    lights/lightControllers/ILightController.cpp \
    lights/lightControllers/SimpleLightController.cpp \
        main.cpp \
    heating/HeatingCurrentView.cpp \
    heating/HeatingApp.cpp \
    MainApp.cpp \
    ../common/json/deviceJson.cpp \
    ../common/json/commonEntity.cpp \
    ../common/sender.cpp \
    ../common/receiver/task.cpp \
    ../common/receiver/receiver.cpp \
    ../common/json/requestJson.cpp \
    ../common/messages/headerJson.cpp \
    ../common/messages/messageCommon.cpp \
    ../common/messages/message_old.cpp \
    ../common/subsystems/alarm/alarmSetMessage.cpp \
    ../common/json/jsonSerialization.cpp \
    ../common/messages/replyMessage.cpp \
    ../common/messages/partedMessage.cpp \
    Receiver.cpp \
    MessageHandler.cpp \
    ../common/subsystems/heating/HeatingZoneSettings.cpp \
    monitoring/MonitoringApp.cpp \
    proximitySensor/ProximityMonitor.cpp \
    proximitySensor/tof.cpp \
    voiceCom/VoiceCom.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = qml/lights

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/kprus/
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /home/kprus/rpi-sysroot/usr/include

HEADERS += \
    ../common/NetworkPortPool.hpp \
    ../common/subsystems/AppBase.hpp \
    ../common/subsystems/heating/BoilerSettingsMessage.hpp \
    ../common/subsystems/heating/HeatingRetrieveMessage.hpp \
    ../common/subsystems/heating/HeatingRetrieveStatistics.hpp \
    ../common/subsystems/heating/PumpSettingsMessage.hpp \
    ../common/subsystems/schedule/ScheduleDictionary.hpp \
    ../common/subsystems/schedule/ScheduleEventTypes.hpp \
    ../common/subsystems/topology/topologyMessages.hpp \
    ../common/subsystems/lights/LightControllerSettings.hpp \
    ../common/subsystems/lights/LightsRetrieveMessage.hpp \
    ../common/subsystems/lights/LightsDictionary.hpp \
    alarm/AlarmMainView.hpp \
    healthcheck/HealthCheck.hpp \
    heating/HeatingBoilerSettings.hpp \
    heating/HeatingCommon.hpp \
    heating/HeatingCurrentView.hpp \
    heating/HeatingApp.hpp \
    MainApp.hpp \
    ../common/json/deviceJson.hpp \
    ../common/json/commonEntity.hpp \
    ../common/sender.hpp \
    ../common/receiver/task.hpp \
    ../common/receiver/receiver.hpp \
    ../common/json/requestJson.hpp \
    ../common/json/nicknames.hpp \
    ../common/messages/message_old.hpp \
    ../common/messages/messageCommon.hpp \
    ../common/messages/headerJson.hpp \
    ../common/subsystems/alarm/alarmSetMessage.hpp \
    ../common/json/jsonSerialization.hpp \
    ../common/messages/replyMessage.hpp \
    ../common/messages/partedMessage.hpp \
    Receiver.hpp \
    ../common/CommonDefinitions.hpp \
    Components.hpp \
    MessageHandler.hpp \
    ../common/subsystems/heating/HeatingDictionary.hpp \
    ../common/subsystems/heating/HeatingZoneSettings.hpp \
    heating/HeatingStatistics.hpp \
    heating/zoneSettings/ZoneControl.hpp \
    heating/zoneSettings/ZoneSetting.hpp \
    lights/LightsApp.hpp \
    lights/LightsView.hpp \
    lights/lightControllers/ColorLightController.hpp \
    lights/lightControllers/DimmableLightController.hpp \
    lights/lightControllers/ILightController.hpp \
    lights/lightControllers/SimpleLightController.hpp \
    monitoring/MonitoringApp.hpp \
    proximitySensor/tof.h \
    proximitySensor/ProximityMonitor.hpp \
    voiceCom/VoiceCom.hpp

DISTFILES += \
    parter.png \
    pietro.png \
    resources/icon_flame_off.jpg \
    resources/icon_flame_on.jpg


#unix:!macx: LIBS += -L$$PWD/../../raspi/sysroot/usr/local/qt5pi/lib/

#INCLUDEPATH += $$PWD/../../raspi/sysroot/usr/local/qt5pi/include
#DEPENDPATH += $$PWD/../../raspi/sysroot/usr/local/qt5pi/include

#unix:!macx: LIBS += -L$$PWD/../../raspi/sysroot/usr/local/qt5pi/lib/

#INCLUDEPATH += $$PWD/../../raspi/sysroot/usr/local/qt5pi/include
#DEPENDPATH += $$PWD/../../raspi/sysroot/usr/local/qt5pi/include
