import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

Item {
    id: dimmableLightController
    width: 45
    height: 45
    property alias mouseArea: mouseArea
    property alias dimmableLightController: dimmableLightController
    property alias dimmableLightControllerY: dimmableLightController.y
    property alias dimmableLightControllerX: dimmableLightController.x
    property alias popup: popup
    property alias slider: slider
    property alias image: image

    Image {
        width: 45
        id: image
        visible: true
        fillMode: Image.PreserveAspectFit
        source: "dimmableLightOff.png"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        pressAndHoldInterval : 500
    }

    Popup {
            id: popup
            width: 300
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
            }
        }
}
