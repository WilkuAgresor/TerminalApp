import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    id: splash
    width: 1200
    height: 800
    property alias button8: button8
    property alias button6: button6
    property alias button2: button2
    property alias button4: button4
    property alias button1: button1
    property alias button3: button3
    property alias button5: button5

    property alias image: image
    font.capitalization: Font.AllUppercase

    header: Label {
        text: qsTr("System Automatyki Domowej")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Image {
        id: image
        x: 148
        y: 48
        width: 305
        height: 203
        anchors.verticalCenterOffset: -26
        anchors.horizontalCenterOffset: 375
        z: 2
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        source: "dom1slajd1.jpg"
    }

    Grid {
        id: grid
        x: 150
        y: 150
        width: 424
        height: 467
        flow: Grid.TopToBottom
        spacing: 50

        Button {
            id: button1
            width: 100
            height: 100
            text: qsTr("1")
        }

        Button {
            id: button4
            width: 100
            height: 100
            text: qsTr("4")
        }

        Button {
            id: button7
            width: 100
            height: 100
            text: qsTr("7")
        }

        Button {
            id: button2
            width: 100
            height: 100
            text: qsTr("2")
        }

        Button {
            id: button5
            width: 100
            height: 100
            text: qsTr("5")
        }

        Button {
            id: button8
            width: 100
            height: 100
            text: qsTr("8")
        }

        Button {
            id: button3
            width: 100
            height: 100
            text: qsTr("3")
        }

        Button {
            id: button6
            width: 100
            height: 100
            text: qsTr("6")
        }

        Button {
            id: button9
            width: 100
            height: 100
            text: qsTr("9")
        }







    }
}
