import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.0


SimpleLightControllerForm {    
    id: simpleLightController
    Image {
        width: 40
        fillMode: Image.PreserveAspectFit
        visible: true
        source: "lightOff.png"

        property var locked: false

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if(parent.locked == true)
                {
                    parent.source = "lightOff.png"
                    parent.locked = false
                }
                else
                {
                    parent.source = "lightOn.png"
                    parent.locked = true
                }
            }
        }

    }
}
