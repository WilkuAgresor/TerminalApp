import QtQuick 2.12

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

    function addZoneControlPanel( name, setterVal, curTemp )
    {
        var component = Qt.createComponent("tempSetter/TempSetter.qml")
        var object = component.createObject(heatGrid)
        object.button.text = name
        object.setter.value = setterVal
     //   object.curTemp.clear()
     //   object.curTemp.append(curTemp)

        object.objectName = "heatZoneControlPanel_" + name
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
        heatingSetWidget.unselectAll()
    }
    rightPanel.resetButton.onClicked :
    {
        heatingSetWidget.unselectAll()
    }
    rightPanel.modeComboBox.onActivated:
    {
        heatingSetWidget.selectedHeatingMode(rightPanel.modeComboBox.currentIndex)
    }
}
