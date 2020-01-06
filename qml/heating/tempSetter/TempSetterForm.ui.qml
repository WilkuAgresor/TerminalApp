import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: tempSetter
    width: 255
    height: 130
    layer.mipmap: false
    transformOrigin: Item.Center
    property alias onOff: onOff
    property alias button: button
    property alias setter: setter

    SpinBox {
        id: setter
        objectName: "heatZoneSetter"
        width: 255
        height: 78
        anchors.top: onOff.bottom
        anchors.topMargin: -40
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 12
        stepSize: 50
        to: 2600
        from: 1300
        value: 2200
        spacing: 6
        transformOrigin: Item.Center

        property int decimals: 2
        property real realValue: value / 100
        x: 0
        y: 64
    }

    Switch {
        id: onOff
        x: 76
        y: 34
        height: 70
        text: qsTr("OFF")

        anchors.top: button.bottom
        anchors.topMargin: -15
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: button
        x: 43
        objectName: "heatZoneMultiSelectButton"
        width: 170
        height: 44
        text: qsTr("NAZWA")
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        checkable: true
        font.pointSize: 12
    }


}

/*##^##
Designer {
    D{i:1;anchors_y:40}D{i:3;anchors_y:0}
}
##^##*/
