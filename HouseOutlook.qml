import QtQuick
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

HouseOutlookForm {

    id: houseOutlook
    signal planeChanged(int selectedPlane)
    signal settingsChanged(string name, int x, int y, int plane)

    property int currentPlane: 0
    property int newSettingX: 0
    property int newSettingY: 0


    TabBar {
        id: control
        width: parent.width / 2
        TabButton {
            text: qsTr("Parter")
            width: Math.max(100, control.width / 4)
            onClicked:
            {
                pietroImage.visible = false
                parterImage.visible = true
                planeChanged(0)
                currentPlane = 0
            }
        }
        TabButton {
            text: qsTr("Piętro")
            width: Math.max(100, control.width / 4)
            onClicked:
            {
                parterImage.visible = false
                pietroImage.visible = true
                planeChanged(1)
                currentPlane = 1
            }
        }
        TabButton {
            text: qsTr("Podwórko")
            width: Math.max(100, control.width / 4)
            onClicked:
            {
                pietroImage.visible = false
                parterImage.visible = true
                planeChanged(0)
                currentPlane = 0
            }
        }
    }


//    MenuBar {
//        x: 0
//        y: 0
//        id: houseOutlookMenu
//        Menu {
//            title: qsTr("Poziom")
//            Action {
//                text: qsTr("Podwórko")
//                onTriggered:
//                {
//                    parterImage.visible = false
//                    pietroImage.visible = false
//                    planeChanged(2)
//                    currentPlane = 2
//                }
//            }
//            MenuSeparator { }
//            Action
//            {
//                text: qsTr("Parter")
//                onTriggered:
//                {
//                    pietroImage.visible = false
//                    parterImage.visible = true
//                    planeChanged(0)
//                    currentPlane = 0
//                }
//            }
//            MenuSeparator { }
//            Action
//            {
//                text: qsTr("Piętro")
//                onTriggered:
//                {
//                    parterImage.visible = false
//                    pietroImage.visible = true
//                    planeChanged(1)
//                    currentPlane = 1
//                }
//            }
//            MenuSeparator { }
//            Action { text: qsTr("Strych") }
//        }
//        Menu {
//            title: qsTr("&Edit")
//            Action { text: qsTr("Cu&t") }
//            Action { text: qsTr("&Copy") }
//            Action { text: qsTr("&Paste") }
//        }
//    }

    /// SETTINGS
    settingsLightButton.onClicked:
    {
        settingsLightLabel.visible = !settingsLightLabel.visible
        settingsLightSelector.visible = !settingsLightSelector.visible
        settingsLightSaverButton.visible = !settingsLightSaverButton.visible

        if(settingsLightLabel.visible == false)
        {
            changePointer.visible = false
            settingsLightMouseArea.enabled = false
        }
    }
    settingsLightSaverButton.onClicked:
    {
        settingsChanged(settingsLightSelector.currentText, newSettingX, newSettingY, currentPlane)
        changePointer.visible = false
    }

    settingsLightSelector.onActivated:
    {
        if(settingsLightSelector.activeFocus !== "NONE")
        {
            settingsLightMouseArea.enabled = true
            settingsLightLabel.text = "x: y: plane:"
        }
    }

    settingsLightMouseArea.onClicked:
    {
        if (mouse.button === Qt.LeftButton)
        {
            newSettingX = mouse.x
            newSettingY = mouse.y
            settingsLightLabel.text = "x: " + newSettingX + " y: "+newSettingY + " plane: "+currentPlane
            settingsLightMouseArea.enabled = false
            changePointer.x = newSettingX - 25
            changePointer.y = newSettingY - 25
            changePointer.visible = true
        }
    }

    function populateSettingsSelector(entityList)
    {
        settingsLightSelector.model = entityList
    }
}
