import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Page {
    id: houseViewPage
    width: 1280
    height: 640
    property alias settingsLightMouseArea: settingsLightMouseArea
    property alias settingsLightLabel: settingsLightLabel
    property alias settingsLightSelector: settingsLightSelector
    property alias settingsLightSaverButton: settingsLightSaverButton
    property alias settingsLightButton: settingsLightButton
    property alias pietroImage: pietroImage
    property alias parterImage: parterImage
    property alias changePointer: changePointer

    RowLayout {
        anchors.fill: parent

        StackView {
            id: poziomy
            Layout.rowSpan: 2
            Layout.preferredHeight: 640
            Layout.preferredWidth: 1027

            Image {
                id: pietroImage
                x: 13
                y: 50
                width: 826
                height: 550
                anchors.horizontalCenterOffset: 67
                anchors.horizontalCenter: parent.horizontalCenter
                source: "resources/pietro-rzut3.png"
                visible: false
            }

            Image {
                id: parterImage
                x: 14
                y: 64
                width: 990
                height: 560
                anchors.horizontalCenterOffset: 149
                anchors.horizontalCenter: parent.horizontalCenter
                visible: true
                source: "resources/parter-rzut3.png"
            }
        }
    }

    Button {
        id: settingsLightButton
        objectName: "settingsLightButton"
        x: 25
        y: 557
        text: qsTr("SETTINGS")
    }

    Button {
        visible: false
        id: settingsLightSaverButton
        objectName: "settingsLightSaverButton"
        x: 543
        y: 557
        text: qsTr("SAVE")
    }

    ComboBox {
        visible: false
        id: settingsLightSelector
        objectName: "settingsLightSelector"
        x: 127
        y: 557
        width: 156
        height: 48
    }

    Label {
        visible: false
        id: settingsLightLabel
        objectName: "settingsLightLabel"
        x: 312
        y: 573
        width: 210
        height: 17
        text: qsTr("x: y: plane:")
    }
    MouseArea {
        id: settingsLightMouseArea
        enabled: false
        anchors.fill: parent
        propagateComposedEvents: true
    }

    Rectangle {
        visible: false
        id: changePointer
        width: 50
        height: 50
        color: "red"
    }
}

/*##^##
Designer {
    D{i:3;anchors_x:38;anchors_y:30;invisible:true}D{i:4;invisible:true}D{i:1;anchors_x:0;anchors_y:0}
}
##^##*/

