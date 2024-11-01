import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 262
    height: 250

    property alias selectAllButton: selectAllButton
    property alias unselectAllButton: unselectAllButton
    property alias multiSetter: multiSetter
    property alias applyButton: applyButton

    Column {
        id: column
        height: 180
        spacing: 5
        anchors.fill: parent

        Button {
            id: selectAllButton
            text: qsTr("Zaznacz Wszystkie")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id: unselectAllButton
            text: qsTr("Odznacz Wszystkie")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Column {
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            Text {
                id: multiSetterLabel
                text: qsTr("Ustaw wiele")
                styleColor: "#000000"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }

            SpinBox {
                id: multiSetter
                objectName: "heatZoneSetter"
                height: 78
                font.strikeout: false
                rightPadding: 78
                leftPadding: 78
                bottomPadding: 12
                topPadding: 12
                font.preferShaping: true
                padding: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                font.pointSize: 11
                stepSize: 50
                to: 2600
                from: 1300
                value: 2200
                spacing: 6
                transformOrigin: Item.Center

                property int decimals: 2
                property real realValue: value / 100
            }
        }
    }

    Button {
        id: applyButton
        y: 206
        text: qsTr("Zastosuj")
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
    }
}

/*##^##
Designer {
    D{i:7;anchors_x:39}
}
##^##*/

