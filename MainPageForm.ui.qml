import QtQuick
import QtQuick.Controls
import QtMultimedia

Page {
    id: mainPage
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Strona główna testowa")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
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
