import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../../"

Page {
    id: page
    width: 1280
    height: 640
    objectName: "HeatingBoilerSettings"

    signal centralHeatingTempSetChange(int value)
    signal centralHeatingModeChange(bool value)

    //0 - central heating 0
    //1 - central heating 1
    //2 - hot water
    signal centralHeatingPumpChange(int index, bool value)
    signal hotWaterTempSetChange(int value)

    //antilegionella mode changed
    signal antiLegionellaModeChange(bool value)

    //central heating temperature spinbox
    property alias winterBoilerTempSet: winterBoilerTempSet
    //hot water temperature spinbox
    property alias hotWaterTempSet: hotWaterTempSet
    //central heating mode selector tabMenu
    property alias centralHeatingModeSelectorTab: centralHeatingModeSelectorTab

    //circulation pumps (parter, pietro, CWU)
    property alias centralHeatingPump0: centralHeatingPump0
    property alias centralHeatingPump1: centralHeatingPump1
    property alias hotWaterPump: hotWaterPump

    //antilegionella mode switch
    property alias antiLegionella: antiLegionella

    //    settable boiler settings
    //    const QString JSON_ENABLE_CENTRAL_HEATING = "ec";
    //    const QString JSON_ENABLE_HOT_WATER = "ehw"; -- zawsze aktywne
    //    const QString JSON_CENTRAL_HEATING_TEMP_SET = "chts";
    //    const QString JSON_MAX_CENTRAL_HEATING_TEMP_SET = "mchts";
    //    const QString JSON_HOT_WATER_TEMP_SET = "hwts";
    property int chts: 27
    property int mchts: 35
    property bool ec: true
    property int hwts: 36

    // #define JSON_IS_CENTRAL_HEATING_ON "icho"
    // #define JSON_IS_HOT_WATER_ON "ihw"
    // #define JSON_IS_FLAME_ON "ifo"
    // #define JSON_CENTRAL_HEATING_TEMP "cht"
    // #define JSON_MAX_CENTRAL_HEATING_TEMP "mcht"
    // #define JSON_HOT_WATER_TEMP "hwt"
    // #define JSON_CONNECTION_STATUS "cons"
    // #define JSON_RETURN_TEMP "ret"
    // #define JSON_PRESSURE "pres"
    property bool icho: true
    property bool ihw: false
    property bool ifo: true
    property int cht: 30
    property int mcht: 35
    property int hwt: 35
    property string conStat: ""
    property int ret: 23
    property real pres: 180

    //custom properties
    property bool ialeg: false
    property bool ispmp0: true //co parter
    property bool ispmp1: true //co pietro
    property bool ispmp2: false //cwu

    //more complicated variables
    property bool isCentralHeatingActive: icho && ifo
    property bool isHotWaterActive: ihw && ifo

    Row {
        id: row
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 0

        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 50

        GroupBox {
            id: centralHeatingBox
            width: 322
            height: 450
            title: qsTr("Centralne Ogrzewanie")

            Column {
                id: column
                anchors.fill: parent
                anchors.bottomMargin: 131

                Column {
                    id: column2
                    width: parent.width

                    Label {
                        id: label1
                        width: parent.width

                        text: qsTr("Wybór trybu pracy")
                    }

                    TabBar {
                        id: centralHeatingModeSelectorTab
                        width: parent.width
                        contentHeight: 80
                        currentIndex: ec ? 0 : 1
                        visible: true
                        objectName: "centralHeatingModeSelector"

                        TabButton {
                            text: qsTr("Zima")
                        }
                        TabButton {
                            text: qsTr("Lato")
                        }
                    }
                }

                StackLayout {
                    id: modeSelector
                    width: parent.width
                    currentIndex: centralHeatingModeSelectorTab.currentIndex

                    Page {
                        id: page1
                        Layout.margins: 7
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                        Column {
                            id: column1
                            Label {
                                id: winterBoilerTempSetLabel
                                text: qsTr("Zadana Temperatura Wody Grzewczej")
                                topPadding: 25
                            }

                            SpinBox {
                                id: winterBoilerTempSet
                                height: 70
                                wheelEnabled: false
                                editable: false
                                to: mchts
                                from: 25
                                width: 300
                                value: chts
                            }
                            Row {
                                id: row1
                                width: parent.width
                                topPadding: 25
                                leftPadding: 40
                                spacing: 20
                                Label {
                                    id: winterCurrentTemp
                                    height: 40
                                    text: qsTr("Obecna temperatura: ") + cht + "\xB0 C"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }

                                Image {
                                    id: imageOn
                                    width: 30
                                    height: 40
                                    source: isCentralHeatingActive ? "flame_icon_on.png" : "flame_icon_off.png"
                                }
                            }
                            Row {
                                width: parent.width
                                topPadding: 25
                                leftPadding: 40
                                spacing: 20
                                Label {
                                    text: qsTr("Pompa obiegowa parter")
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    height: centralHeatingPump0.height
                                }
                                Switch {
                                    id: centralHeatingPump0
                                    checked: ispmp0
                                }
                            }

                            Row {
                                width: parent.width
                                topPadding: 25
                                leftPadding: 40
                                spacing: 20
                                Label {
                                    text: "Pompa obiegowa piętro"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    height: centralHeatingPump1.height
                                }

                                Switch {
                                    id: centralHeatingPump1
                                    checked: ispmp1
                                }
                            }
                        }
                    }
                    Page {
                        Label {
                            text: "dupa2"
                        }
                    }
                }
            }
        }

        Column {

            spacing: 20

            GroupBox {
                id: centralHeatingBox1
                width: 322
                height: 330
                title: qsTr("Ciepła Woda Użytkowa")
                Column {
                    anchors.fill: parent

                    Column {
                        Label {
                            text: qsTr("Zadana Temperatura CWU")
                            topPadding: 10
                        }

                        SpinBox {
                            id: hotWaterTempSet
                            width: 300
                            height: 70
                            wheelEnabled: false
                            to: 70
                            from: 35
                            value: hwts
                        }

                        Row {
                            width: parent.width
                            topPadding: 25
                            leftPadding: 40
                            spacing: 20

                            Label {
                                id: hotWaterCurTempLabel
                                height: 40
                                text: qsTr("Obecna temperatura: ") + hwt + "\xB0 C"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                            Image {
                                id: howWaterImage
                                width: 30
                                height: 40
                                source: isHotWaterActive ? "flame_icon_on.png" : "flame_icon_off.png"
                            }
                        }

                        Row {
                            width: parent.width
                            topPadding: 25
                            leftPadding: 40
                            spacing: 20
                            Label {
                                text: "Pompa obiegowa"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                height: hotWaterPump.height
                            }

                            Switch {
                                id: hotWaterPump
                                checked: ispmp2
                            }
                        }

                        Row {
                            width: parent.width
                            topPadding: 25
                            leftPadding: 40
                            spacing: 20
                            Label {
                                text: "Antylegionella"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                height: antiLegionella.height
                            }

                            Switch {
                                id: antiLegionella
                                checked: ialeg
                            }
                        }
                    }
                }
            }

            GroupBox {
                id: centralHeatingBox2
                width: 322
                height: 130
                title: qsTr("Pozostałe Parametry Techniczne")
                Column {
                    anchors.fill: parent
                    Column {
                        leftPadding: 40

                        Label {
                            text: qsTr(
                                      "Ciśnienie w instalacji: ") + pres / 100 + "bar"
                            topPadding: 10
                        }
                        Label {
                            text: qsTr("Temperatura powrotu: ") + ret + "\xB0 C"
                            topPadding: 10
                        }
                        Label {
                            text: qsTr("Status sterownika: " + conStat)
                            topPadding: 10
                        }
                    }
                }
            }
        }
    }
}
