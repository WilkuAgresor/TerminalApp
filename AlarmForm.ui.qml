import QtQuick
import QtQuick.Controls

Page {
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Alarm")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page Alarm.")
        anchors.centerIn: parent
    }
}
