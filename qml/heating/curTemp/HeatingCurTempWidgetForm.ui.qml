import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    id: curTempElement
    property alias currentTemp: currentTemp
    width: 30
    height: 30
    visible: false
    property alias curTempElementHeight: curTempElement.height
    property alias curTempElementWidth: curTempElement.width
    property alias curTempElementY: curTempElement.y
    property alias curTempElementX: curTempElement.x

    ColumnLayout {
        id: column
        anchors.fill: parent

        spacing: 10

        Text {
            id: currentTemp
            width: curTempElement.width
            height: curTempElement.height
            text: qsTr("")
            font.bold: true
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
