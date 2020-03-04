import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColorLightControllerForm {
    id: dimmableLightForm
    property var isOn: false

    signal lightDimmChanged(int dimm)

    function setState( state )
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

    function setVisible( isVisible )
    {
        visible = isVisible
    }

    function setDimm( dimm )
    {
        slider.value = dimm
    }

    mouseArea.onClicked: {
        if(isOn == true)
        {
            setState(false)
        }
        else
        {
            setState(true)
        }
    }

    mouseArea.onPressAndHold: {
        popup.open()
    }

    slider.onMoved: {
        lightDimmChanged(slider.value)
    }
}