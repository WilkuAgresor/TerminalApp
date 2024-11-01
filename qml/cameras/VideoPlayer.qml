import QtQuick
import QtQuick.Controls
import QtMultimedia
import QtQuick.Layouts

Item {

    id: videoplayerItem
    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
    Layout.fillWidth: true
    Layout.fillHeight: true


    property int position: 0

    Layout.columnSpan: position===1 ? 2 : 1
    Layout.rowSpan: position===1 ? 2 : 1

    property alias busyIndicator: busyIndicator
    property alias mouseAreaEnabled: mouseArea.enabled

    property string videoSource: ""

    Rectangle {
        id: playerWindow

        width: parent.width
        height: parent.height

        color: "#00000000"
        border.color: "#00000000"

        visible: true

        MediaPlayer {
            id: player
            source: videoplayerItem.videoSource
            videoOutput: videoOutput
            audioOutput: AudioOutput {}

            onErrorOccurred : {
                print("stream error: " + errorString)
                print("media state: " + mediaStatus)
            }
            onPlaybackStateChanged : {

                if(playbackState != 1)
                {
                    refreshIcon.visible = true
                }
                else
                {
                    refreshIcon.visible = false
                    busyIndicator.visible = false
                    busyIndicator.running = false
                }

                print("playback state changed: " + playbackState.toString() )
                print("media state: " + mediaStatus.toString())
            }
            onPlayingChanged : {
                print ("playing changed: " + playing)
                print("media state: " + mediaStatus.toString())
            }
            Component.onCompleted:
            {
                play()
            }
        }

        VideoOutput {
            id: videoOutput
            anchors.fill: parent
        }

        Image {
            id: refreshIcon
            width: 120
            height: 120
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/resources/refresh-icon.png"
            visible: false
        }

        BusyIndicator {
            id: busyIndicator
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            running: true
            visible: true
        }

        MouseArea {
            id: mouseArea
            enabled : true
            anchors.fill: parent
            onPressed:  {
                if(player.playbackState != 1)
                {
                    refreshIcon.visible = false
                    busyIndicator.visible = true
                    busyIndicator.running = true
                    player.setSource("")
                    player.setSource(videoSource)
                    player.play()
                }
                // else
                // {
                //     player.stop()
                //     player.setSource("")
                //     refreshIcon.visible = true
                //     busyIndicator.visible = false
                //     busyIndicator.running = false
                // }
            }
        }
    }

    function play()
    {
        player.play()
    }

    function setSource( source )
    {
        player.setSource(source)
        //player.play()
    }

}
