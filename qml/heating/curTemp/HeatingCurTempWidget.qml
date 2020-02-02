import QtQuick 2.12
import QtQuick.Controls.Material 2.12

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
