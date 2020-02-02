import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import "../../"

Item {
    width: 1280
    height: 640
    Layout.alignment: Qt.AlignLeft | Qt.AlignRight | Qt.AlignHCenter

    HouseOutlook {
        id: houseOutlook
        anchors.fill: parent

        ColorLightController {
            id: colorLightController
            x: 680
            y: 158
        }

        DimmableLightController {
            id: simpleLightController1
            x: 680
            y: 300
        }

        DimmableLightController {
            id: simpleLightController2
            x: 736
            y: 468
        }

        SimpleLightController {
            id: simpleLightController3
            x: 633
            y: 505
        }

        SimpleLightController {
            id: simpleLightController4
            x: 560
            y: 505
        }

        SimpleLightController {
            id: simpleLightController5
            x: 435
            y: 434
        }

        SimpleLightController {
            id: simpleLightController6
            x: 449
            y: 140
        }
    }
}
