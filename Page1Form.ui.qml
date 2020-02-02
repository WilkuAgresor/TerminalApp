import QtQuick 2.12
import QtQuick.Controls 2.12

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

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    Image {
        id: image
        x: 59
        y: 61
        width: 800
        source: "rzut.png"
        fillMode: Image.PreserveAspectFit
    }
}
