import QtQuick

HeatingSetWidgetForm {
    id: heatingSetWidget
    objectName: "heatingSetWidget"
    signal buttonClicked(string butName)
    signal applyMultiSetter(int value)
    signal saveChanges()
    signal resetChanges()
    signal selectAll()
    signal unselectAll()
    signal selectedHeatingMode(int index)

    function addZoneControlPanel( name, setterVal, isOn )
    {
        var component = Qt.createComponent("tempSetter/TempSetter.qml")
        var object = component.createObject(heatGrid)
        object.button.text = name
        object.setter.value = setterVal

        object.objectName = "heatZoneControlPanel_" + name

        if(isOn)
        {
            object.setOn()
        }
        else
        {
            object.setOff()
        }
    }

    function clearProfiles()
    {
        rightPanel.modeComboBox.editable = true
        rightPanel.modeComboBox.profileList.clear()
        rightPanel.modeComboBox.editable = false
    }

    function addProfile(name)
    {
        rightPanel.modeComboBox.editable = true
        rightPanel.modeComboBox.profileList.append({text: name})
        rightPanel.modeComboBox.editable = false
    }

    function selectProfile(id)
    {
        rightPanel.modeComboBox.currentIndex = id
    }

    function setBusy(value)
    {
        rightPanel.busyIndicator.visible = value
        rightPanel.busyIndicator.running = value
    }

    rightPanel.heatMultiSetter.applyButton.onClicked :
    {
        heatingSetWidget.applyMultiSetter(rightPanel.heatMultiSetter.multiSetter.value)
    }
    rightPanel.heatMultiSetter.selectAllButton.onClicked :
    {
        heatingSetWidget.selectAll()
    }
    rightPanel.heatMultiSetter.unselectAllButton.onClicked :
    {
        heatingSetWidget.unselectAll()
    }
    rightPanel.saveButton.onClicked :
    {
        heatingSetWidget.saveChanges()
    }
    rightPanel.resetButton.onClicked :
    {
        heatingSetWidget.resetChanges()
    }
    rightPanel.modeComboBox.onActivated:
    {
        heatingSetWidget.selectedHeatingMode(rightPanel.modeComboBox.currentIndex)
    }
}
