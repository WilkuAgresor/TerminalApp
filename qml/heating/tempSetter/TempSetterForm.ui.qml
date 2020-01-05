import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: tempSetter
    width: 262
    height: 160
    property alias button: button
    property alias setter: setter

    Column {
        id: column
        anchors.fill: parent

        Button {
            id: button
            objectName: "heatZoneMultiSelectButton"
            width: 170
            height: 44
            text: qsTr("NAZWA")
            anchors.horizontalCenter: parent.horizontalCenter
            checkable: true
            font.pointSize: 12
        }

        SpinBox {
            id: setter
            objectName: "heatZoneSetter"
            width: 262
            height: 78
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 12
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
