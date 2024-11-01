import QtQuick
import QtQuick.Controls.Material

HeatingCurTempWidgetForm {

    id: curTempWidget

    currentTemp.color: Material.color(Material.Grey, Material.Shade50)


    function setCurrentTemperature(value)
    {
        currentTemp.text = value
    }
    function setVisibility(value)
    {
        curTempWidget.visible = value
    }

    property int plane
}
