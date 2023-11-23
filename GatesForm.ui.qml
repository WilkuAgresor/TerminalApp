import QtQuick 2.12
import QtQuick.Controls 2.12
import VLCQtl 1.0

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

//    Rectangle {
//        x: 0
//        y:0
//        width: 640
//        height: 350
//        color: "black"

//        VlcVideoPlayer {
//            id: vidwidget
//            anchors.fill: parent
//            url: "rtsp://admin:@192.168.100.206/stream=1"
//        }
//    }

}
