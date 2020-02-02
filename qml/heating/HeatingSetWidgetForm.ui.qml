import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "tempSetter"

Page {
    id: page
    property alias heatGrid: heatGrid
    property alias rightPanel: rightPanel
    width: 1280
    height: 640

    //    header: Label {
    //        text: qsTr("Ogrzewanie - Ustawienia temperatury")
    //        font.pixelSize: Qt.application.font.pixelSize * 2
    //        padding: 10
    //    }

    RowLayout {
        anchors.fill: parent
//        anchors.fill: parent
//        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        GridLayout {
            id: heatGrid
            width: 0
            height: 0
            rowSpacing: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.leftMargin: 0
            Layout.rightMargin: 0
            rows: 3
            columns: 4

            Layout.topMargin: 15
        }

        HeatRightPanel {
            id: rightPanel
            y: 0

            width: 220
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.rightMargin: 25
            Layout.topMargin: 0
            Layout.fillHeight: false
        }
    }

}

/*##^##
Designer {
    D{i:1;anchors_height:0;anchors_width:0}
}
##^##*/
