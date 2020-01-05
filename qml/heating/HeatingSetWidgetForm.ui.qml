import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "tempSetter"

Page {
    id: page
    width: 1280
    height: 680
    property alias heatGrid: heatGrid
    property alias rightPanel: rightPanel

    header: Label {
        text: qsTr("Ogrzewanie - Ustawienia temperatury")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    RowLayout {
        anchors.rightMargin: 5
        anchors.fill: parent

        GridLayout {
            id: heatGrid
            x: 0
            y: 35
            width: 1014
            height: 561
            rows: 3
            columns: 4
        }

        HeatRightPanel {
            id: rightPanel
            y: 80
            Layout.fillWidth: true
        }
    }
}
