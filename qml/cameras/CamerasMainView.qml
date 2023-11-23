import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
import VLCQtl 1.0

CamerasMainViewForm {
    id: camerasMainPage

    Text {
        id: monitoringStreamUrl
        visible: false
        text: qsTr("rtsp://admin:@192.168.100.206/stream=1")
    }

    Rectangle {
        x: 25
        y: 25
        width: parent.width - 50
        height: parent.height - 50
        color: "#00000000"
        border.color: "#00000000"

        Component {
            id: monitoringVideoPlayer
            VlcVideoPlayer {
                anchors.fill: parent
                id: monitoringVlcVideoPlayer
                objectName: "monitoringVlcVideoPlayer"
                url: monitoringStreamUrl.text
                autoplay: true
            }            
        }

        Loader {
            anchors.fill: parent
            id: monitoringLoader
            objectName: "cameraVideoLoader"
            visible: true
            active: visible
            sourceComponent: monitoringVideoPlayer
        }
    }


    header: TabBar {
        id: control
        width: parent.width / 2

        TabButton {
            text: qsTr("Ulica")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.206/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Podjazd")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.203/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Ogród")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.202/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Taras")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.204/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Drewutnia")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.201/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Wybieg")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.205/stream=1"
                monitoringLoader.visible = true
            }
        }
        TabButton {
            text: qsTr("Garaż")
            width: Math.max(100, control.width / 7)
            onClicked:
            {
//                monitoringStreamUrl.text = "rtsp://admin:@192.168.100.203/stream=1"
                monitoringLoader.visible = false
            }
        }


    }

    Timer {
       id: updater
       interval: 200
       repeat: true
       property int s: 0
       onTriggered: {
         switch (s) {
         case 0:
           monitoringLoader.visible = false
           ++s
           break
         case 1:
           ++s
           break
         case 2:
             monitoringLoader.visible = true
           s = 0
           stop()
         }
       }
     }

    function refreshVideoPlayer()
    {
        if(monitoringLoader.visible)
        {
            updater.start();
        }
    }

}
