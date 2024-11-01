import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColorLightControllerForm {
    id: dimmableLightForm
    property bool isOn: false

    signal lightOnChanged(bool isOn)
    signal lightDimmChanged(int dimm)
    signal lightColorChanged(string color)

    function setStateInternal( state )
    {
        if(isOn !== state )
        {
           if(state === false)
           {
               image.source = "colorLightOff.png"
               isOn = false
           }
           else
           {
               image.source = "colorLightOn.png"
               isOn = true
           }
        }
    }

    function setState( state )
    {
        setStateInternal( state )
    }

    function setVisible( isVisible )
    {
        visible = isVisible
    }

    function setDimm( dimm )
    {
        slider.value = dimm
    }

    function setColor( color )
    {
        colorPicker.setColor( color )
    }

    mouseArea.onClicked: {
        lightOnChanged( isOn )
    }

    mouseArea.onPressAndHold: {
        popup.open()
    }

    slider.onMoved: {
        lightDimmChanged(slider.value)
    }
    colorPicker.onLightColorChanged: {
        lightColorChanged(color)
    }
}
