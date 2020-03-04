import QtQuick 2.12

LightsMainViewForm {
    id: lightsMainView
    objectName: lightsMainView

    signal planeChanged(int plane)

    houseOutlook.onPlaneChanged:
    {
        lightsMainView.planeChanged(selectedPlane)
    }

    function addSimpleLightController( name, isOn, x, y)
    {
        var controllerObject = Qt.createComponent("SimpleLightController.qml")

        var object = controllerObject.createObject(lightsMainView)

        object.objectName = "lightsSimpleControl_" + name
        object.simpleLightControllerX = x
        object.simpleLightControllerY = y
        object.setState(isOn)
    }

    function addDimmableLightController(name, isOn, x, y, dimm)
    {
        var component = Qt.createComponent("DimmableLightController.qml")
        var object = component.createObject(lightsMainView)

        object.objectName = "lightsDimmableControl_" + name
        object.dimmableLightControllerX = x
        object.dimmableLightControllerY = y
        object.setState(isOn)
        object.setDimm(dimm)
    }

    function addColorLightController(name, isOn, x, y, dimm)
    {
        var component = Qt.createComponent("ColorLightController.qml")
        var object = component.createObject(lightsMainView)

        object.objectName = "lightsColorControl_" + name
        object.x = x
        object.y = y
        object.setState(isOn)
        object.setDimm(dimm)
//        object.setColor(color)
    }
}
