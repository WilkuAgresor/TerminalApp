import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    id: colorLightController
    width: 45
    height: 45
    property alias mouseArea: mouseArea
    property alias lightControllerY: colorLightController.y
    property alias lightControllerX: colorLightController.x
    property alias popup: popup
    property alias slider: slider
    property alias image: image
    property alias colorPicker: colorPicker

    Image {
        width: 45
        id: image
        visible: true
        fillMode: Image.PreserveAspectFit
        source: "colorLightOff.png"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        pressAndHoldInterval : 500
        propagateComposedEvents: true
    }

    Popup {
            id: popup
            width: 280
            x:  - width/2 + parent.width/2
            y: - height/2 + parent.height/2
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

            background: Rectangle
            {
                color: Material.backgroundColor
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
                    from: 0
                    to: 100
                    anchors.left: parent.left
                    anchors.right: parent.right
                }

                ColorPicker
                {
                    id: colorPicker
                    width: 300
                }

            }
        }
}
