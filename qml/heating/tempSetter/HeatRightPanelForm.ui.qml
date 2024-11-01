import QtQuick
import QtQuick.Controls

Item {
    id: heatRightPanel
    width: 220
    height: 550
    property alias modeComboBox: modeComboBox
    property alias resetButton: resetButton
    property alias saveButton: saveButton
    property alias heatMultiSetter: heatMultiSetter
    property alias busyIndicator: busyIndicator

    Column {
        id: column1
        height: 550

    anchors.fill: parent

    Column {
        id: column
        width: 220
        height: 500
        spacing: 20

        Button {
            id: saveButton
            text: qsTr("Zapisz")
            //            anchors.top: parent.top
            //            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.left: parent.left
        }

        Button {
            id: resetButton
            text: qsTr("Odrzuć")
            //            anchors.top: button.bottom
            anchors.right: parent.right
            anchors.left: parent.left
        }

        Column {
            anchors.right: parent.right
            anchors.left: parent.left
            Text {
                id: comboBoxDescription
                text: qsTr("Tryb Pracy")
                anchors.bottomMargin: 156
                anchors.right: parent.right
                anchors.left: parent.left
                font.pixelSize: 12
            }

            ComboBox {
                id: modeComboBox

                property alias profileList: profileList

                editable: true
                anchors.right: parent.right
                //            anchors.top: button1.bottom
                anchors.left: parent.left
                model: ListModel {
                    id: profileList
                }
            }
        }

        HeatMultiSetter {
            id: heatMultiSetter
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }
    }
    BusyIndicator {
        id: busyIndicator
        anchors.horizontalCenter: parent.horizontalCenter
        running: true
        visible: true
    }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:0;anchors_y:0}
}
##^##*/

