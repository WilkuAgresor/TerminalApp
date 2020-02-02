import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.0


DimmableLightControllerForm {
    id: dimmableLightController
    Image {
        width: 40
        fillMode: Image.PreserveAspectFit
        visible: true
        source: "dimmableLightOff.png"

        property var locked: false

        MouseArea {
            id: resetGroupbox

            x: -1280
            y: -800
            width: 2560
            height: 1600

            enabled: false

            onClicked:
            {
                groupbox.visible = false
                enabled = false
            }

        }

        MouseArea {
            anchors.fill: parent
            pressAndHoldInterval : 500

            onClicked: {
                if(parent.locked == true)
                {
                    parent.source = "dimmableLightOff.png"
                    parent.locked = false
                }
                else
                {
                    parent.source = "dimmableLightOn.png"
                    parent.locked = true
                }
            }
            onPressAndHold: {
                groupbox.visible = true
                resetGroupbox.enabled = true
            }
        }

        GroupBox {

                id: groupbox
                width: 200

                x: parent.x - width/2 + parent.width/2
                y: parent.y - height/2 + parent.height/2
                visible: false

                background: Rectangle
                {
                    color: Material.background
                    border.color: Material.foreground
                }

                Column
                {
                    anchors.fill: parent
                    Layout.alignment: Qt.AlignHCenter

                    Label {
                        text: qsTr("Jasność")
                        horizontalAlignment: Text.AlignHCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    Slider {
                        id: slider
                        value: 0.5
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }
                }
            }

    }
}
