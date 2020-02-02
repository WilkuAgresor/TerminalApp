import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

import "qml/heating"
import "qml/lights"

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Tabs")

    objectName: "mainWindow"

    flags: Qt.Window | Qt.FramelessWindowHint
  //  visibility: Window.FullScreen

    SplashForm {
        id: splashScreen
        visible: true
        objectName: "splashScreen"

        property int password: 0

        function addAndValidate()
        {
            password = password + 1
            if (password == 4) {
                acceptPassword()
            }
        }

        function acceptPassword()
        {
            visible = false
            mainLayout.visible = true
            tabBar.visible = true
        }

        button4.onClicked: {
            addAndValidate()
    }
        button2.onClicked: {
            addAndValidate()
    }
        button6.onClicked: {
            addAndValidate()
    }
        button8.onClicked: {
            addAndValidate()
    }

    }

    StackLayout {
        id: mainLayout
        anchors.fill: parent
        Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

        currentIndex: tabBar.currentIndex
        visible: false
        objectName: "mainLayout"

        ShortcutsForm {
            objectName: "shortcutsForm"
        }

        AlarmForm {
            objectName: "alarmForm"

        }

//        LightsMainView
//        {
//            objectName: "lightsMainView"
//        }

            Page
            {
                StackLayout {

                    Layout.alignment: Qt.AlignVCenter
                    id: lightsLayous
                    currentIndex: lightsTabBar.currentIndex

                    LightsMainView
                    {
                        objectName: "lightsMainView"
                    }
                }
                header: TabBar {
                    id: lightsTabBar
                    contentHeight: 80
                    currentIndex: lightsLayous.currentIndex

                    TabButton {
                        text: qsTr("Oświetlenie")
                    }
                }
            }

        Page
        {

        StackLayout {

            Layout.alignment: Qt.AlignVCenter
            id: heatLayout
            currentIndex: heatTabBar.currentIndex

            HeatingCurTemp
            {
                objectName: "heatingCurTemp"
            }

            HeatingSetWidget
            {
                objectName: "heatingSetWidget"
            }

            HeatingModesForm {
                objectName: "heatingModesForm"
            }
        }
        header: TabBar {
            id: heatTabBar
            contentHeight: 80
            currentIndex: heatLayout.currentIndex

            TabButton {
                text: qsTr("Podgląd")
            }
            TabButton {
                text: qsTr("Ustawienia temperatury")
            }
            TabButton {
                text: qsTr("Ustawienia trybów pracy")
            }
        }

        }

        GatesForm {
            objectName: "gatesForm"

        }
    }

    footer: TabBar {
        id: tabBar
        contentHeight: 80
        currentIndex: mainLayout.currentIndex
        visible: false
        objectName: "tabBar"


        TabButton {
            text: qsTr("Skróty")
        }
        TabButton {
            text: qsTr("Alarm")
        }
        TabButton {
            text: qsTr("Oświetlenie")
        }
        TabButton {
            text: qsTr("Ogrzewanie")
        }
        TabButton {
            text: qsTr("Bramy")
        }
    }
}
