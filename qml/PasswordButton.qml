import QtQuick 2.12

/**
 * This is the type implements one single key button in the InputPanel
 * The code has been derived from
 * http://tolszak-dev.blogspot.de/2013/04/qplatforminputcontext-and-virtual.html
 * Copyright 2015 Uwe Kindler
 * Licensed under MIT see LICENSE.MIT in project root
 */
Item {
    id:root

    width: 150
    height: 150

    /**
     * The background color of this button
     */
    property color color: "#35322f"

    /**
     * The key text to show in this button
     */
    property string text

    /**
     * The font for rendering of text
     */
    property alias font: txt.font

    /**
     * The color of the text in this button
     */
    property alias textColor: txt.color

    /**
     * This property holds the pressed status of the key.
     */
    property alias isPressed: buttonMouseArea.pressed

      /**
     * This property holds the highlighted status of the key
     * The highlighted status is a little bit different from the pressed status
     * If the user releases the key, it is not pressed anymore, but it is still
     * highlighted for some milliseconds
     */
    property bool isHighlighted: false

    /**
     * Sets the show preview attribute for the character preview key popup
     */
    property bool showPreview: true

    /**
     * Sets the key repeat attribute.
     * If the repeat is enabled, the key will repeat the input events while held down.
     * The default is false.
     */
    property bool repeat: false

    /**
     * Sets the key code for input method processing.
     */
    property int key

    /**
     * Sets the display text - this string is rendered in the keyboard layout.
     * The default value is the key text.
     */
    property alias displayText: txt.text

    /**
     * Sets the function key attribute.
     */
    property bool functionKey: false

    signal clicked()
    signal pressed()
    signal released()

    Rectangle {
        anchors.fill: parent
        radius: height / 30
        color: isHighlighted ? Qt.tint(root.color, "#801e6fa7") : root.color
        Text {
            id: txt
            color: "white"
            anchors.margins: parent.height / 6
            anchors.fill: parent
            fontSizeMode: Text.Fit
            font.pixelSize: height
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: root.text
        }
        MouseArea {
            id: buttonMouseArea
            anchors.fill: parent
            onClicked: root.clicked()
            onPressed: root.pressed()
            onReleased: root.released()
        }
    }

    Timer {
        id: highlightTimer
        interval: 100
        running: !isPressed
        repeat: false

        onTriggered: {
            isHighlighted = false;
        }
    }
}
