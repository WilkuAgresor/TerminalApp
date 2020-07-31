import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

DimmableLightControllerForm {
    id: dimmableLightForm
    property var isOn: false

    signal lightOnChanged(bool isOn)
    signal lightDimmChanged(int dimm)

    function setStateInternal( state )
    {
        if(isOn !== state )
        {
           if(state === false)
           {
               image.source = "dimmableLightOff.png"
               isOn = false
           }
           else
           {
               image.source = "dimmableLightOn.png"
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

    mouseArea.onClicked: {
        lightOnChanged(isOn)
    }

    mouseArea.onPressAndHold: {
        popup.open()
    }

    slider.onMoved: {
        lightDimmChanged(slider.value)
    }
}
