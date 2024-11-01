import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

CamerasMainViewForm {
    id: camerasMainPage
    width: 1280
    height: 600

    Component {
        id: dynamicCameraComponent

        GridLayout {
            id: gridLayout
            objectName: "camerasMainViewGrid"

            anchors.fill: parent
            anchors.margins: 5
            columns: 3

            property int activeCameraId : 1

            VideoPlayer{
                id: cam6
                mouseAreaEnabled: true
                position : 1
                videoSource: "rtsp://admin:@192.168.100.206/stream=1"
            }
            VideoPlayer{
                id: cam5
                mouseAreaEnabled: true
                videoSource: "rtsp://admin:@192.168.100.205/stream=1"
            }
            VideoPlayer{
                id: cam4
                mouseAreaEnabled: true
                videoSource: "rtsp://admin:@192.168.100.204/stream=1"
            }
            VideoPlayer{
                id: cam3
                mouseAreaEnabled: true
                videoSource: "rtsp://admin:@192.168.100.203/stream=1"
            }
            VideoPlayer{
                id: cam2
                mouseAreaEnabled: true
                videoSource: "rtsp://admin:@192.168.100.202/stream=1"
            }
            VideoPlayer{
                id: cam1
                mouseAreaEnabled: true
                videoSource: "rtsp://admin:@192.168.100.201/stream=1"
            }
        }
    }

    Loader {
        anchors.fill: parent
        id: monitoringLoader
        objectName: "CameraVideoLoader"
        visible: true
        active: false
        sourceComponent: dynamicCameraComponent
    }

    function play()
    {
        monitoringLoader.active = true
    }
    function stop()
    {
        monitoringLoader.active = false
    }


    // function addCameraView(cameraName, streamUrl)
    // {
    //     var controllerObject = Qt.createComponent("VideoPlayer.qml")

    //     var object = controllerObject.createObject(gridLayout, {videoSource:streamUrl})
    //     object.play()

    //     // object.objectName = "cameraView_" + cameraName
    //     // object.setSource(streamUrl)
    //     // object.setName(cameraName)
    //     // object.play()
    // }



    // VideoPlayer
    // {
    //     id: player
    // }

    // header: TabBar {
    //     id: control
    //     width: parent.width / 2

    //     TabButton {
    //         text: qsTr("Ulica")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.206/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Podjazd")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.203/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Ogród")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.202/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Taras")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.204/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Drewutnia")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.201/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Wybieg")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             player.setSource("rtsp://admin:@192.168.100.205/stream=1")
    //             player.play()
    //         }
    //     }
    //     TabButton {
    //         text: qsTr("Garaż")
    //         width: Math.max(100, control.width / 7)
    //         onClicked:
    //         {
    //             //player.setSource("rtsp://admin:@192.168.100.203/stream=1")
    //             player.play()
    //         }
    //     }
    // }

}
