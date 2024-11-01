import QtQuick

LightsMainViewForm {
    id: lightsMainView
    objectName: lightsMainView

    signal planeChanged(int plane)
    signal guiSettingsChange(string name, int x, int y, int plane)

    houseOutlook.onPlaneChanged:
    {
        lightsMainView.planeChanged(selectedPlane)
    }
    houseOutlook.onSettingsChanged:
    {
        //extract a half of the light image size (width =50)
        lightsMainView.guiSettingsChange(name, x - 25, y - 25, plane)
    }

    function addSimpleLightController( name, isOn, x, y)
    {
        var lightName = "lightsSimpleControl_" + name

        var controllerObject = Qt.createComponent("SimpleLightController.qml")

        var object = controllerObject.createObject(lightsMainView)

        object.objectName = lightName
        object.lightControllerX = x
        object.lightControllerY = y
        object.setStateInternal(isOn)
    }

    function addDimmableLightController(name, isOn, x, y, dimm)
    {
        var component = Qt.createComponent("DimmableLightController.qml")
        var object = component.createObject(lightsMainView)

        object.objectName = "lightsDimmableControl_" + name
        object.lightControllerX = x
        object.lightControllerY = y
        object.setStateInternal(isOn)
        object.setDimm(dimm)
    }

    function addColorLightController(name, isOn, x, y, dimm, color)
    {
        var component = Qt.createComponent("ColorLightController.qml")
//        console.error("Errors:")
//        console.error(component.errorString())
        var object = component.createObject(lightsMainView)

        object.objectName = "lightsColorControl_" + name
        object.lightControllerX = x
        object.lightControllerY = y
        object.setStateInternal(isOn)
        object.setDimm(dimm)
        object.setColor(color)
    }

    function populateSettingsSelector(entityList)
    {
        houseOutlook.populateSettingsSelector(entityList)
    }
}
