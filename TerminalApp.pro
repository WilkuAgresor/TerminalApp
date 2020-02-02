QT += quick widgets
CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../common/subsystems/heating/HeatingRetrieveMessage.cpp \
    ../common/subsystems/topology/topologyMessages.cpp \
    heating/zoneSettings/ZoneControl.cpp \
    heating/zoneSettings/ZoneSetting.cpp \
        main.cpp \
    heating/HeatingCurrentView.cpp \
    heating/HeatingApp.cpp \
    MainApp.cpp \
    ../common/simplecrypt/simplecrypt.cpp \
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
    Receiver.cpp \
    MessageHandler.cpp \
    ../common/subsystems/heating/HeatingZoneSettings.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = qml/heating

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../common/subsystems/heating/HeatingRetrieveMessage.hpp \
    ../common/subsystems/topology/topologyMessages.hpp \
    heating/HeatingCurrentView.hpp \
    heating/HeatingApp.hpp \
    MainApp.hpp \
    ../common/simplecrypt/simplecrypt.hpp \
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
    Receiver.hpp \
    ../common/CommonDefinitions.hpp \
    Components.hpp \
    MessageHandler.hpp \
    ../common/subsystems/heating/HeatingDictionary.hpp \
    ../common/subsystems/heating/HeatingZoneSettings.hpp \
    heating/zoneSettings/ZoneControl.hpp \
    heating/zoneSettings/ZoneSetting.hpp

DISTFILES += \
    parter.png \
    pietro.png

