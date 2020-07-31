import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

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
