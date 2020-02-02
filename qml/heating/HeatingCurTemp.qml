import QtQuick 2.12

HeatingCurTempForm {
    id: curTempView

    signal planeChanged(int plane)

    houseOutlook.onPlaneChanged:
    {
        curTempView.planeChanged(selectedPlane)
    }

    function addCurTempWidget( name, value, plane, x, y, height, width, fontSize )
    {
        var component = Qt.createComponent("curTemp/HeatingCurTempWidget.qml")
        var object = component.createObject(curTempView)

        object.objectName = "heatZoneCur_" + name
        object.currentTemp.text = value
        object.currentTemp.font.pointSize = fontSize
        object.curTempElementX = x
        object.curTempElementY = y
        object.curTempElementHeight = height
        object.curTempElementWidth = width
    }
}
