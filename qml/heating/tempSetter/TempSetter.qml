import QtQuick 2.12

TempSetterForm {
    objectName: "ddd"

    signal valueChanged (int value)
    signal switchedOnOff (bool value)

    onOff.onCheckedChanged: {
        if(!onOff.checked)
        {
            onOff.text = qsTr("OFF");
        }
        else
        {
            onOff.text = qsTr("ON");
        }
        switchedOnOff(onOff.checked)
    }

    setter.onValueChanged: {
        valueChanged(setter.value)
    }

    function setButtonText ( name )
    {
        button.text = name
    }
    function setSetterValue ( value )
    {
        setter.value = value
    }

    function checkForMultiUpdate()
    {
        button.checked = true
    }
    function uncheckForMultiUpdate()
    {
        button.checked = false
    }

    function setOn()
    {
        if(!onOff.checked)
        {
            onOff.toggle()
            onOff.text = qsTr("ON");
        }
    }

    function setOff()
    {
        if(onOff.checked)
        {
            onOff.text = qsTr("OFF");
            onOff.toggle()
        }
    }


//    function setCurTemp ( value )
//    {
//        curTemp.clear()
//        curTemp.append(value)
//    }

    setter.textFromValue: function(value, locale) {
        return Number(value / 100).toLocaleString(locale, 'f', setter.decimals) + "\xB0 C"
    }
    setter.valueFromText: function(text, locale) {
        return Number.fromLocaleString(locale, text) * 100
    }

}
