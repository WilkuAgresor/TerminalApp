import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

SimpleLightControllerForm {
    id: simpleLightForm
    property var isOn: false

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
        if(isOn !== state)
        {
            lightOnChanged( state )
            setStateInternal( state )
        }
    }

    function setVisible( isVisible )
    {
        visible = isVisible
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
}
