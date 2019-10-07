import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Page {
    id: page
    width: 1280
    height: 680
    property alias heatRefreshButton: heatRefreshButton
    property alias multiSetter: multiSetter
    property alias multiSetterSaveButton: multiSetterSaveButton
    property alias garderoba1Check: garderoba1Check
    property alias garderoba2Check: garderoba2Check
    property alias lazienka3Check: lazienka3Check
    property alias lazienka2Check: lazienka2Check
    property alias sypialnia4Check: sypialnia4Check
    property alias sypialnia3Check: sypialnia3Check
    property alias sypialnia2Check: sypialnia2Check
    property alias sypialnia1Check: sypialnia1Check
    property alias lazienka1Check: lazienka1Check
    property alias gabinetCheck: gabinetCheck
    property alias wiatrolapCheck: wiatrolapCheck
    property alias salonCheck: salonCheck
    property alias heatStateButton: heatStateButton
    property alias modeSetterLabel: modeSetterLabel
    property alias modeSetter: modeSetter
    property alias garderoba2Setter: garderoba2Setter
    property alias garderoba2CurTemp: garderoba2CurTemp
    property alias lazienka2Setter: lazienka2Setter
    property alias lazienka2CurTemp: lazienka2CurTemp
    property alias sypialnia4Setter: sypialnia4Setter
    property alias sypialnia4CurTemp: sypialnia4CurTemp
    property alias lazienka3Setter: lazienka3Setter
    property alias lazienka3CurTemp: lazienka3CurTemp
    property alias garderoba1Setter: garderoba1Setter
    property alias garderoba1CurTemp: garderoba1CurTemp
    property alias sypialnia3Setter: sypialnia3Setter
    property alias sypialnia3CurTemp: sypialnia3CurTemp
    property alias sypialnia2Setter: sypialnia2Setter
    property alias sypialnia2CurTemp: sypialnia2CurTemp
    property alias sypialnia1Setter: sypialnia1Setter
    property alias sypialnia1CurTemp: sypialnia1CurTemp
    property alias gabinet: gabinet
    property alias wiatrolapCurTemp: wiatrolapCurTemp
    property alias salonCurTemp: salonCurTemp
    property alias wiatrolap: wiatrolap
    property alias gabinetCurTemp: gabinetCurTemp
    property alias lazienka1: lazienka1
    property alias lazienka1CurTemp: lazienka1CurTemp
    property alias lazienka1Setter: lazienka1Setter
    property alias gabinetSetter: gabinetSetter
    property alias salonSetter: salonSetter
    property alias wiatrolapSetter: wiatrolapSetter

    Grid {
        id: heatGrid
        x: 0
        y: 35
        width: 1014
        height: 561
        rows: 3
        columns: 4

        Column {
            id: salon
            width: 255
            height: 179
            Button {
                id: salonCheck
                objectName: "salonCheck"
                width: 170
                height: 44
                text: qsTr("SALON")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: salonCurTemp
                objectName: "salonCurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: salonSetter
                objectName: "salonSetter"
                width: 262
                height: 78
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

        Column {
            id: wiatrolap
            width: 255
            height: 179

            Button {
                id: wiatrolapCheck
                objectName: "wiatrolapCheck"

                width: 170
                height: 44
                text: qsTr("WIATROŁAP")
                font.pointSize: 12
                checkable: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: wiatrolapCurTemp
                objectName: "wiatrolapCurTemp"

                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            SpinBox {
                id: wiatrolapSetter
                objectName: "wiatrolapSetter"

                width: 262
                height: 78
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

        Column {
            id: gabinet
            width: 255
            height: 179

            Button {
                id: gabinetCheck
                objectName: "gabinetCheck"
                width: 170
                height: 44
                text: qsTr("GABINET")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: gabinetCurTemp
                objectName: "gabinetCurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: gabinetSetter
                objectName: "gabinetSetter"
                width: 262
                height: 78
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
        Column {
            id: lazienka1
            width: 255
            height: 179
            Button {
                id: lazienka1Check
                objectName: "lazienka1Check"
                width: 170
                height: 44
                text: qsTr("ŁAZIENKA 1")
                font.pointSize: 12
                checkable: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: lazienka1CurTemp
                objectName: "lazienka1CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            SpinBox {
                id: lazienka1Setter
                objectName: "lazienka1Setter"
                width: 262
                height: 78
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

        Column {
            id: sypialnia1
            width: 255
            height: 179

            Button {
                id: sypialnia1Check
                objectName: "sypialnia1Check"
                width: 170
                height: 44
                text: qsTr("SYPIALNIA 1")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: sypialnia1CurTemp
                objectName: "sypialnia1CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: sypialnia1Setter
                objectName: "sypialnia1Setter"
                width: 262
                height: 78
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

        Column {
            id: sypialnia2
            width: 255
            height: 179
            Button {
                id: sypialnia2Check
                objectName: "sypialnia2Check"
                width: 170
                height: 44
                text: qsTr("SYPIALNIA 2")
                font.pointSize: 12
                checkable: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: sypialnia2CurTemp
                objectName: "sypialnia2CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: sypialnia2Setter
                objectName: "sypialnia2Setter"
                width: 262
                height: 78
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

        Column {
            id: sypialnia3
            width: 255
            height: 179
            Button {
                id: sypialnia3Check
                objectName: "sypialnia3Check"
                width: 170
                height: 44
                text: qsTr("SYPIALNIA 3")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: sypialnia3CurTemp
                objectName: "sypialnia3CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: sypialnia3Setter
                objectName: "sypialnia3Setter"
                width: 262
                height: 78
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
        Column {
            id: garderoba1
            width: 255
            height: 179
            Button {
                id: garderoba1Check
                objectName: "garderoba1Check"
                width: 170
                height: 44
                text: qsTr("GARDEROBA 1")
                font.pointSize: 12
                checkable: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: garderoba1CurTemp
                objectName: "garderoba1CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            SpinBox {
                id: garderoba1Setter
                objectName: "garderoba1Setter"
                width: 262
                height: 78
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

        Column {
            id: lazienka3
            width: 255
            height: 179

            Button {
                id: lazienka3Check
                objectName: "lazienka3Check"
                width: 170
                height: 44
                text: qsTr("ŁAZIENKA 3")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: lazienka3CurTemp
                objectName: "lazienka3CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: lazienka3Setter
                objectName: "lazienka3Setter"
                width: 262
                height: 78
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

        Column {
            id: sypialnia4
            width: 255
            height: 179

            Button {
                id: sypialnia4Check
                objectName: "sypialnia4Check"
                width: 170
                height: 44
                text: qsTr("SYPIALNIA 4")
                font.pointSize: 12
                checkable: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: sypialnia4CurTemp
                objectName: "sypialnia4CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: sypialnia4Setter
                objectName: "sypialnia4Setter"
                width: 262
                height: 78
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

        Column {
            id: lazienka2
            width: 255
            height: 179
            Button {
                id: lazienka2Check
                objectName: "lazienka2Check"
                width: 170
                height: 44
                text: qsTr("ŁAZIENKA 2")
                checkable: true
                font.pointSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: lazienka2CurTemp
                objectName: "lazienka2CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: lazienka2Setter
                objectName: "lazienka2Setter"
                width: 262
                height: 78
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

        Column {
            id: garderoba2
            width: 255
            height: 179
            Button {
                id: garderoba2Check
                objectName: "garderoba2Check"
                width: 170
                height: 44
                text: qsTr("GARDEROBA 2")
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 12
                checkable: true
            }

            Text {
                id: garderoba2CurTemp
                objectName: "garderoba2CurTemp"
                width: 262
                height: 38
                color: "#ffffff"
                text: qsTr("25,00\xB0 C")
                font.pointSize: 13
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            SpinBox {
                id: garderoba2Setter
                objectName: "garderoba2Setter"
                width: 262
                height: 78
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

    Column {
        id: column
        x: 1020
        y: 150
        width: 230
        height: 430
        anchors.verticalCenterOffset: -52
        anchors.verticalCenter: parent.verticalCenter
        spacing: 53

        Button {
            id: heatRefreshButton
            x: 43
            objectName: "heatRefreshButton"
            width: 200
            height: 60
            text: qsTr("Odśwież")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: heatStateButton
            objectName: "heatStateButton"
            width: 200
            height: 60
            text: qsTr("Zastosuj")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Column {
            id: column1
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: modeSetterLabel
                text: qsTr("Tryb pracy")
                anchors.horizontalCenter: parent.horizontalCenter
            }

            ComboBox {
                id: modeSetter
                objectName: "heatModeSetter"
                width: 200
                height: 60
                anchors.horizontalCenter: parent.horizontalCenter

                model: ["Dzień", "Noc"]
            }
        }

        Column {
            id: column2
            anchors.horizontalCenter: parent.horizontalCenter

            SpinBox {
                id: multiSetter
                objectName: "heatMultiSetter"
                width: 230
                height: 78
                Layout.preferredHeight: 78
                font.pointSize: 12
                stepSize: 50
                to: 2600
                from: 1300
                value: 2200
                spacing: 6

                property int decimals: 2
                property real realValue: value / 100
            }

            Button {
                id: multiSetterSaveButton
                objectName: "multiSetterSaveButton"
                width: 200
                height: 48
                text: qsTr("Ustaw Zaznaczone")
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
