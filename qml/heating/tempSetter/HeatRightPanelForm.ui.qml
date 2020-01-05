import QtQuick 2.12
import QtQuick.Controls 2.13

Item {
    id: heatRightPanel
    width: 200
    height: 500
    property alias modeComboBox: modeComboBox
    property alias resetButton: resetButton
    property alias saveButton: saveButton
    property alias heatMultiSetter: heatMultiSetter

    Column {
        id: column
        height: 600
        spacing: 20
        anchors.fill: parent

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
                anchors.right: parent.right
                //            anchors.top: button1.bottom
                anchors.left: parent.left
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
}

/*##^##
Designer {
    D{i:1;anchors_x:0;anchors_y:0}
}
##^##*/

