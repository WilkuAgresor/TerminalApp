import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
