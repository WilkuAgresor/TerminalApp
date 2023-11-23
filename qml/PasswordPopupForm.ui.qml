import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    id: page
    width: 1280
    height: 800

    Row {
        id: row
        x: 186
        y: 113
        spacing: 6
        layer.wrapMode: ShaderEffectSource.Repeat
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        layoutDirection: Qt.LeftToRight

        Grid {
            id: grid
            spacing: 6
            columns: 3

            PasswordButton {
                id: passwordButton1
                key: 1
                text: qsTr("1")
            }

            PasswordButton {
                id: passwordButton2
                key: 2
                text: qsTr("2")
            }

            PasswordButton {
                id: passwordButton3
                key: 3
                text: qsTr("3")
            }

            PasswordButton {
                id: passwordButton4
                key: 4
                text: qsTr("4")
            }

            PasswordButton {
                id: passwordButton5
                key: 5
                text: qsTr("5")
            }

            PasswordButton {
                id: passwordButton6
                key: 6
                text: qsTr("6")
            }

            PasswordButton {
                id: passwordButton7
                key: 7
                text: qsTr("7")
            }

            PasswordButton {
                id: passwordButton8
                key: 8
                text: qsTr("8")
            }

            PasswordButton {
                id: passwordButton9
                key: 9
                text: qsTr("9")
            }

            PasswordButton {
                id: passwordButton10
                text: qsTr("*")
            }

            PasswordButton {
                id: passwordButton0
                text: qsTr("0")
            }

            PasswordButton {
                id: passwordButton11
                text: qsTr("#")
            }
        }

        Column {
            id: column
            spacing: 6

            PasswordButton {
                functionKey: true
                id: backspaceButton
                text: qsTr("\u2190")
            }

            PasswordButton {
                id: enterButton
                functionKey: true
                height: 306
                text: "\u2713"
            }

            PasswordButton {
                id: clearButton
                functionKey: true
                text: qsTr("cancel")
            }
        }
    }
}
