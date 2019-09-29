import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3

import terminal.backend 1.0


ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Tabs")

    objectName: "mainWindow"


    flags: Qt.Window | Qt.FramelessWindowHint
  //  visibility: Window.FullScreen

    BackEnd {
        id: backend
        objectName: "backend"

    }

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
        currentIndex: tabBar.currentIndex
        visible: false
        objectName: "mainLayout"

        ShortcutsForm {
            objectName: "shortcutsForm"
        }

        AlarmForm {
            objectName: "alarmForm"

        }

        LightsForm {
            objectName: "lightsForm"

        }

        HeatingForm
        {
            id: heatingForm
            objectName: "heatingForm"

            signal buttonClicked(string butName)
            signal applyMultiSetter()

            salonCheck.onClicked: {
                heatingForm.buttonClicked("salon")
            }
            wiatrolapCheck.onClicked: {
                heatingForm.buttonClicked("wiatrolap")
            }
            gabinetCheck.onClicked: {
                heatingForm.buttonClicked("gabinet")
            }
            lazienka1Check.onClicked: {
                heatingForm.buttonClicked("lazienka1")
            }
            sypialnia1Check.onClicked: {
                heatingForm.buttonClicked("sypialnia1")
            }
            sypialnia2Check.onClicked: {
                heatingForm.buttonClicked("sypialnia2")
            }
            sypialnia3Check.onClicked: {
                heatingForm.buttonClicked("sypialnia3")
            }
            garderoba1Check.onClicked: {
                heatingForm.buttonClicked("garderoba1")
            }
            lazienka3Check.onClicked: {
                heatingForm.buttonClicked("lazienka3")
            }
            sypialnia4Check.onClicked: {
                heatingForm.buttonClicked("sypialnia4")
            }
            lazienka2Check.onClicked: {
                heatingForm.buttonClicked("lazienka2")
            }
            garderoba2Check.onClicked: {
                heatingForm.buttonClicked("garderoba2")
            }
            multiSetterSaveButton.onClicked: {
                heatingForm.applyMultiSetter()
            }



            wiatrolapSetter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            wiatrolapSetter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            salonSetter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            salonSetter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            gabinetSetter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            gabinetSetter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            lazienka1Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            lazienka1Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            lazienka2Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            lazienka2Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            lazienka3Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            lazienka3Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            sypialnia1Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            sypialnia1Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            sypialnia2Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            sypialnia2Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            sypialnia3Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            sypialnia3Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            sypialnia4Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            sypialnia4Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            garderoba1Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            garderoba1Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            garderoba2Setter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            garderoba2Setter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
            multiSetter.textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
            }
            multiSetter.valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }

        }

        GatesForm {
            objectName: "gatesForm"

        }
    }

    footer: TabBar {
        id: tabBar
        contentHeight: 120
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
