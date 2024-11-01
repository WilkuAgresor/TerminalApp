import QtQuick

Item {
    id: simpleLightController
    width: 45
    height: 45

    property alias mouseArea: mouseArea
    property alias simpleLightController: simpleLightController
    property alias lightControllerY: simpleLightController.y
    property alias lightControllerX: simpleLightController.x

    property alias image: image

    Image {
        width: 50
        id: image
        visible: true
        fillMode: Image.PreserveAspectFit
        source: "lightOff.png"
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        propagateComposedEvents: true
    }
}
