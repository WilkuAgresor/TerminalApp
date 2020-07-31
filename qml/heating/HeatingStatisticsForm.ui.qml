import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtCharts 2.11

import "statistics"

Page {
    id: page

    width: 1280
    height: 640
    property alias sensorTypeBox: sensorTypeBox
    property alias timeRangeBox: timeRangeBox
    property alias zoneListScrollView: zoneListScrollView
    property alias zoneListView: zoneListView
    property alias heatingStatisticsChartView: heatingStatisticsChartView

    RowLayout {
        anchors.fill: parent

        ChartView {
            id: heatingStatisticsChartView

            property alias xaxis: xaxis
            property alias yaxis: yaxis


            objectName: "heatingStatisticsChartView"
            height: 640
            width: 980

            antialiasing: true
            theme: ChartView.ChartThemeDark

            Layout.alignment: Qt.AlignVCenter | Qt.AlignTop

            ValueAxis {
                id: yaxis
                tickCount: 15
                minorTickCount: 0

                min: 15
                max: 30
            }

            DateTimeAxis {
                id: xaxis
                format: "HH:mm"
                tickCount: 8
                labelsAngle: 90
            }
        }

        ColumnLayout {
            id: column
            Layout.fillHeight: true
            Layout.fillWidth: true

                ScrollView {
                    id: zoneListScrollView
                    ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                    ScrollBar.vertical.policy: ScrollBar.AlwaysOn

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                ZoneListView{
                    id: zoneListView
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

        }
        }

        ColumnLayout {
            id: column2
            spacing: 30

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter | Qt.AlignTop

            ComboBox {
                id: sensorTypeBox
                font.pointSize: 10
                model: ["Powietrze", "Podłoga", "Razem"]
            }

            ComboBox {
                id: timeRangeBox
                font.pointSize: 10
                model: ["Dzień", "Dwa dni", "Tydzień"]
            }
        }
    }
}
