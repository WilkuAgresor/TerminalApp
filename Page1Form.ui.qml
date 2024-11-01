import QtQuick
import QtQuick.Controls

Page {
    id: page
    width: 1200
    height: 800

    header: Label {
        text: qsTr("System Automatyki Domowej")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }
}
