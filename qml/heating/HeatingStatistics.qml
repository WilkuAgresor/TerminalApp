import QtQuick
import QtCharts

HeatingStatisticsForm {
    id: heatingStatistics
    objectName: "heatingStatistics"
    signal zoneChecked(string zoneName, int sensorType, int periodType)
    signal zoneUnchecked(string zoneName, int sensorType, int periodType)

    function toMsecsSinceEpoch(date) {
        var msecs = date.getTime();
        return msecs;
    }

    function getCurrentDate()
    {
        var currentDate = new Date();

        var p = 60 * 60 * 1000; // milliseconds in an hour
        currentDate.setTime( Math.ceil(currentDate.getTime() / p ) * p);
        return currentDate;
    }

    function addLine(name)
    {
        var currentDate = getCurrentDate();

        heatingStatisticsChartView.xaxis.max = currentDate;

        var dateOffset;

        if(timeRangeBox.currentIndex == 0)
        {
            dateOffset = (24*60*60*1000) * (1); //1 day
        }
        else if(timeRangeBox.currentIndex == 1)
        {
            dateOffset = (24*60*60*1000) * (2); //2 days
        }
        else if(timeRangeBox.currentIndex == 2)
        {
            dateOffset = (24*60*60*1000) * (7); //7days
        }


        if(timeRangeBox.currentIndex > 0)
        {
            heatingStatisticsChartView.xaxis.format = "ddd HH:mm"
            heatingStatisticsChartView.xaxis.tickCount = 25
        }
        else
        {
            heatingStatisticsChartView.xaxis.format = "HH:mm"
            heatingStatisticsChartView.xaxis.tickCount = 25
        }

        currentDate.setTime(currentDate.getTime() - dateOffset);
        heatingStatisticsChartView.xaxis.min = currentDate;

        var line = heatingStatisticsChartView.createSeries(ChartView.SeriesTypeLine, name, heatingStatisticsChartView.xaxis, heatingStatisticsChartView.yaxis);
    }

    function removeLines()
    {
        heatingStatisticsChartView.removeAllSeries();
        heatingStatisticsChartView.yaxis.min = 0;
        heatingStatisticsChartView.yaxis.max = 0;
    }

    function addPoint(name, timestamp, value)
    {
        adjustYAxis(value);

        var line = heatingStatisticsChartView.series(name);
        line.append(timestamp,value);
    }

    function removeLine(name)
    {
       var line = heatingStatisticsChartView.series(name);
       heatingStatisticsChartView.removeSeries(line);
    }

    function addZone(zoneName)
    {
        for (var i=0; i < zoneListView.zoneListModel.count; i++)
        {
            if(zoneListView.zoneListModel.get(i).name === zoneName)
            {
                return;
            }
        }

        zoneListView.zoneListModel.append({"name" : zoneName});
    }

    function removeZones()
    {
        zoneListView.zoneListModel.clear();
    }

    function adjustYAxis(value)
    {
        heatingStatisticsChartView.yaxis.min = 15;
        heatingStatisticsChartView.yaxis.max = 30;



//        if(heatingStatisticsChartView.yaxis.min > value || heatingStatisticsChartView.yaxis.min == 0)
//        {
//            heatingStatisticsChartView.yaxis.min = value;
//        }
//        if(heatingStatisticsChartView.yaxis.max < value || heatingStatisticsChartView.yaxis.max == 0)
//        {
//            heatingStatisticsChartView.yaxis.max = value;
//        }
    }

    zoneListView.onZoneChecked:
    {
        heatingStatistics.zoneChecked(zoneName, sensorTypeBox.currentIndex, timeRangeBox.currentIndex)
    }
    zoneListView.onZoneUnchecked:
    {
        heatingStatistics.zoneUnchecked(zoneName, sensorTypeBox.currentIndex, timeRangeBox.currentIndex)
    }

    timeRangeBox.onCurrentIndexChanged:
    {
        removeLines();
        for(var box in zoneListView.children) {
            box.checkState = Qt.Unchecked;
        }
    }

}
