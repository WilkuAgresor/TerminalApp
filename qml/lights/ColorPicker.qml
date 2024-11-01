import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

ColorPickerForm {

    signal lightColorChanged(string color)

    function updateSelectedColor()
    {
        var color = Qt.rgba(sliderR.value/255., sliderG.value/255., sliderB.value/255., 1)
        selectedColorBox.color = color;
        lightColorChanged(color)
    }

    function setColor( color )
    {
        selectedColorBox.color = color
    }

    sliderR.onValueChanged:
    {
        updateSelectedColor()
    }
    sliderG.onValueChanged:
    {
        updateSelectedColor()
    }
    sliderB.onValueChanged:
    {
        updateSelectedColor()
    }
}
