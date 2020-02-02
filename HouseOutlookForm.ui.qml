import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Page {
    id: houseViewPage
    width: 1280
    height: 640
    property alias pietroButton: pietroButton
    property alias parterButton: parterButton
    property alias podworkoButton: podworkoButton
    property alias pietroImage: pietroImage
    property alias parterImage: parterImage

    RowLayout {
        anchors.fill: parent

        StackView {
            id: poziomy
            Layout.rowSpan: 2
            Layout.preferredHeight: 640
            Layout.preferredWidth: 1027

            Image {
                id: pietroImage
                x: 13
                y: 37
                width: 826
                height: 550
                anchors.horizontalCenter: parent.horizontalCenter
                source: "resources/pietro-rzut3.png"
                visible: false
            }

            Image {
                id: parterImage
                x: 14
                y: 51
                width: 990
                height: 560
                anchors.horizontalCenter: parent.horizontalCenter
                visible: true
                source: "resources/parter-rzut3.png"
            }
        }

        Column {
            id: column

            width: 200
            Layout.rightMargin: 20
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            layer.textureMirroring: ShaderEffectSource.NoMirroring

            spacing: 80
            Layout.fillHeight: false
            Layout.fillWidth: true

            Button {
                id: podworkoButton
                height: 130
                text: qsTr("Ogród")
                font.pointSize: 15
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                anchors.leftMargin: 0
            }

            Button {
                id: pietroButton
                height: 130
                text: qsTr("Piętro")
                font.pointSize: 15
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: parterButton
                height: 130
                text: qsTr("Parter")
                font.pointSize: 15
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}

/*##^##
Designer {
    D{i:3;anchors_x:38;anchors_y:30}D{i:4;invisible:true}D{i:1;anchors_x:0;anchors_y:0}
}
##^##*/

