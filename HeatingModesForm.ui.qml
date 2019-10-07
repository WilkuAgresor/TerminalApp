import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Tryby pracy")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("Tutaj możesz ustawić harmonogram zmiany trybów pracy.")
        anchors.centerIn: parent
    }
}