import QtQuick 2.12

Item {
    id: simpleLightController
    width: 45
    height: 45

    property alias mouseArea: mouseArea
    property alias simpleLightController: simpleLightController
    property alias simpleLightControllerY: simpleLightController.y
    property alias simpleLightControllerX: simpleLightController.x

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
    }
}
