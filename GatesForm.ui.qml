import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Bramy")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("Tutaj możesz obsługiwać bramy.")
        anchors.centerIn: parent
    }
}
