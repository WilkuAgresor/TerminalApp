import QtQuick 2.12


HouseOutlookForm {

    id: houseOutlook
    signal planeChanged(int selectedPlane)
    signal settingsChanged(string name, int x, int y, int plane)

    property int currentPlane: 0
    property int newSettingX: 0
    property int newSettingY: 0

    podworkoButton.onClicked:
    {
        parterImage.visible = false
        pietroImage.visible = false
        planeChanged(2)
        currentPlane = 2
    }

    pietroButton.onClicked:
    {
        parterImage.visible = false
        pietroImage.visible = true
        planeChanged(1)
        currentPlane = 1
    }
    parterButton.onClicked:
    {
        pietroImage.visible = false
        parterImage.visible = true
        planeChanged(0)
        currentPlane = 0
    }

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
            settingsLightMouseArea.raise()
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
