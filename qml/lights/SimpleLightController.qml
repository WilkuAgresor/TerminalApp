import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

SimpleLightControllerForm {
    id: simpleLightForm
    property bool isOn: false

    signal lightOnChanged(bool isOn)

    function setStateInternal( state )
    {
        if(isOn !== state )
        {
           if(state === false)
           {
               image.source = "lightOff.png"
               isOn = false
           }
           else
           {
               image.source = "lightOn.png"
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

    mouseArea.onClicked: {
        lightOnChanged(isOn)
    }
}
