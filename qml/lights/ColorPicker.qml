import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Styles 1.4

ColorPickerForm {

    function updateSelectedColor()
    {
        selectedColorBox.color = Qt.rgba(sliderR.value/255., sliderG.value/225., sliderB.value/255., 1);
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
