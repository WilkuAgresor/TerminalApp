import QtQuick 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

Page {
    width: 1200
    height: 800

    header: Label {
        text: qsTr("Bramy")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Video {
        id: cam1Stream
        x: 64
        y: 6
        width: 505
        height: 336
        z: 1
        source: "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"
        autoPlay: true
        opacity: 1.0
        fillMode: Image.Stretch
        muted: false
    }

    Label {
        text: qsTr("Tutaj możesz obsługiwać bramy.")
        anchors.centerIn: parent
    }

    Video {
        id: cam1Stream1
        x: 618
        y: 6
        width: 505
        height: 336
        muted: false
        z: 1
        fillMode: Image.Stretch
        autoPlay: true
        opacity: 1
        source: "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"
    }

    Video {
        id: cam1Stream2
        x: 64
        y: 348
        width: 505
        height: 336
        muted: false
        z: 1
        fillMode: Image.Stretch
        autoPlay: true
        opacity: 1
        source: "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"
    }

    Video {
        id: cam1Stream3
        x: 618
        y: 348
        width: 505
        height: 336
        z: 1
        muted: false
        fillMode: Image.Stretch
        opacity: 1
        autoPlay: true
        source: "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov"
    }
}
