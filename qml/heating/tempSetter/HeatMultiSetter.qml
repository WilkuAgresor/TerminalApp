import QtQuick

HeatMultiSetterForm {

    multiSetter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', multiSetter.decimals) + "\xB0 C"
    }
    multiSetter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }
}
