import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

import "../../"

Page {
    width: 1280
    height: 640
    Layout.alignment: Qt.AlignLeft | Qt.AlignRight | Qt.AlignHCenter

    property alias houseOutlook: houseOutlook

    HouseOutlook {
        id: houseOutlook
        anchors.fill: parent
    }
}
