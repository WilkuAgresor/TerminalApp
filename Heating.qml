import QtQuick 2.9

HeatingForm {    
    id: heatingForm
    objectName: "heatingForm"

    signal buttonClicked(string butName)
    signal applyMultiSetter()

    salonCheck.onClicked: {
        heatingForm.buttonClicked("salon")
    }
    wiatrolapCheck.onClicked: {
        heatingForm.buttonClicked("wiatrolap")
    }
    gabinetCheck.onClicked: {
        heatingForm.buttonClicked("gabinet")
    }
    lazienka1Check.onClicked: {
        heatingForm.buttonClicked("lazienka1")
    }
    sypialnia1Check.onClicked: {
        heatingForm.buttonClicked("sypialnia1")
    }
    sypialnia2Check.onClicked: {
        heatingForm.buttonClicked("sypialnia2")
    }
    sypialnia3Check.onClicked: {
        heatingForm.buttonClicked("sypialnia3")
    }
    garderoba1Check.onClicked: {
        heatingForm.buttonClicked("garderoba1")
    }
    lazienka3Check.onClicked: {
        heatingForm.buttonClicked("lazienka3")
    }
    sypialnia4Check.onClicked: {
        heatingForm.buttonClicked("sypialnia4")
    }
    lazienka2Check.onClicked: {
        heatingForm.buttonClicked("lazienka2")
    }
    garderoba2Check.onClicked: {
        heatingForm.buttonClicked("garderoba2")
    }
    multiSetterSaveButton.onClicked: {
        heatingForm.applyMultiSetter()
    }



    wiatrolapSetter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    wiatrolapSetter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    salonSetter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    salonSetter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    gabinetSetter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    gabinetSetter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    lazienka1Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    lazienka1Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    lazienka2Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    lazienka2Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    lazienka3Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    lazienka3Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    sypialnia1Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    sypialnia1Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    sypialnia2Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    sypialnia2Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    sypialnia3Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    sypialnia3Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    sypialnia4Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    sypialnia4Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    garderoba1Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    garderoba1Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    garderoba2Setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    garderoba2Setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
    multiSetter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', wiatrolapSetter.decimals) + "\xB0 C"
    }
    multiSetter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
}
