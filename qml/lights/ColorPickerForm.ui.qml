import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Item {
    width: 280
    height: 250

    property alias sliderG: sliderG
    property alias selectedColorBox: selectedColorBox
    property alias sliderB: sliderB
    property alias sliderR: sliderR

    Column {
        id: column
        spacing: 15
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter

        Label {
            text: qsTr("Kolor")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
        }

        RowLayout {
            id: rowLayout
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

            Slider {
                id: sliderR
                height: 150
                orientation: Qt.Vertical
                from: 0
                to: 255
            }

            Slider {
                id: sliderG
                height: 150
                orientation: Qt.Vertical
                from: 0
                to: 255
            }

            Slider {
                id: sliderB
                height: 150
                orientation: Qt.Vertical
                from: 0
                to: 255
            }

            Rectangle {
                id: selectedColorBox
                width: 100
                height: 100
                color: "#ffffff"
            }
        }
    }
}

/*##^##
Designer {
    D{i:5;anchors_height:100;anchors_width:100}
}
##^##*/
