import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

BoilerSettingsForm {
    id: heatingBoilerSettings

    winterBoilerTempSet.textFromValue: function(value, locale) {
        return Number(value) + "\xB0 C"
    }
    winterBoilerTempSet.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text)
    }

    hotWaterTempSet.textFromValue: function(value, locale) {
        return Number(value) + "\xB0 C"
    }
    hotWaterTempSet.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text)
    }

    centralHeatingModeSelectorTab.onCurrentIndexChanged: {
        if(centralHeatingModeSelectorTab.currentIndex===0)
        {
            centralHeatingModeChange(true)
        }
        else
        {
            centralHeatingModeChange(false)
        }
    }

    winterBoilerTempSet.onValueModified:
    {
        centralHeatingTempSetChange(winterBoilerTempSet.value)
    }

    hotWaterTempSet.onValueModified:
    {
        hotWaterTempSetChange(hotWaterTempSet.value)
    }

    centralHeatingPump0.onToggled:
    {
        centralHeatingPumpChange(0,centralHeatingPump0.checked)
    }

    centralHeatingPump1.onToggled:
    {
        centralHeatingPumpChange(1,centralHeatingPump1.checked)
    }

    hotWaterPump.onToggled:
    {
        centralHeatingPumpChange(2,hotWaterPump.checked)
    }

    antiLegionella.onToggled:
    {
        antiLegionellaModeChange(antiLegionella.checked)
    }

    // //read-only properties
    // #define JSON_IS_CENTRAL_HEATING_ON "icho"
    // #define JSON_IS_HOT_WATER_ON "ihw"
    // #define JSON_IS_FLAME_ON "ifo"
    // #define JSON_CENTRAL_HEATING_TEMP "cht"
    // #define JSON_MAX_CENTRAL_HEATING_TEMP "mcht"
    // #define JSON_HOT_WATER_TEMP "hwt"
    // #define JSON_CONNECTION_STATUS "cons"
    // #define JSON_RETURN_TEMP "ret"
    // #define JSON_PRESSURE "pres"

    // Boiler settings model

//    ListModel {
//        id: boilerSettingsCentralHeatingModel
//        ListElement { name: "Centralne ogrzewanie"; value: true; type: "boolean"; identifier: "ec" }
//        ListElement { name: "Temperatura"; value: 20; type: "integer"; identifier: "chts"}
//    }


//    ListModel {
//        id: boilerSettingsHotWaterModel
//        ListElement { name: "Ciepła woda"; value: false; type: "boolean"; idenifier: "ehw" }
//        ListElement { name: "Temperatura"; value: 30; type: "integer"; identifier: "hwts" }
//    }

//    Component {
//        id: booleanSettingComponent
//        CheckBox {
//            property bool setVal: false
//            checked: setVal

//            onCheckedChanged: {
//                // Here you can emit a signal to update the backend
//            }
//        }
//    }

//    Component {
//        id: integerSettingComponent
//        SpinBox {
//            property int setVal: 0
//            value: setVal
//            stepSize: 1
//            from: 0 // Define minimum and maximum values as needed
//            to: 100

//            onValueChanged: {
//                // Here you can emit a signal to update the backend
//            }
//        }
//    }

//    Component {
//        id: headerLabel
//        Label {
//            text: "header label"
//        }
//    }

//    Row{

//    ListView {

//        width: 250
//        height: 400
//        model: boilerSettingsCentralHeatingModel

//        delegate:     Item {
//            width: parent.width
//            height: 50
//            // anchors.centerIn: parent

//            RowLayout {
//                spacing: 15

//                Layout.alignment: Qt.AlignCenter
//                Label { text: model.name }
//                Loader {
//                    sourceComponent: {
//                        if (model.type === "boolean") {
//                            booleanSettingComponent
//                        } else if (model.type === "integer") {
//                            integerSettingComponent
//                        }
//                    }
//                    onLoaded: {
//                        item.setVal = model.value;
//                        item.objectName = model.identifier;
//                    }
//                }
//            }
//        }
//    }


//    ListView {
//        model: boilerSettingsHotWaterModel
//        width: 250
//        height: 400
//        delegate:     Item {
//            width: parent.width
//            height: 50
//            // anchors.centerIn: parent

//            RowLayout {
//                spacing: 15
//                Label { text: model.name }
//                Loader {
//                    sourceComponent: {
//                        if (model.type === "boolean") {
//                            booleanSettingComponent
//                        } else if (model.type === "integer") {
//                            integerSettingComponent
//                        }
//                    }
//                    onLoaded: {
//                        item.setVal = model.value;
//                        item.objectName = model.identifier;
//                    }
//                }
//            }
//        }
//    }
//    }

//    // ListView {
//    //     x:500
//    //     anchors.fill: parent
//    //     model: boilerSettingsHotWaterModel

//    //     header: headerLabel

//    //     delegate: delegateItem
//    // }

}
