import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {
    id: page
    width: 1280
    height: 680

    header: Label {
        text: qsTr("Ogrzewanie - Podgląd")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

}
