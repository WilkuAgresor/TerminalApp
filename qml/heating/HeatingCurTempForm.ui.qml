import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../"


Page {
    id: page
    width: 1280
    height: 640
    property alias houseOutlook: houseOutlook
    Layout.alignment: Qt.AlignLeft | Qt.AlignRight | Qt.AlignHCenter

//    header: Label {
//        text: qsTr("Ogrzewanie - Podgląd")
//        font.pixelSize: Qt.application.font.pixelSize * 2
//        padding: 10
//    }

    HouseOutlook
    {
        id: houseOutlook
        anchors.fill: parent
    }

}
