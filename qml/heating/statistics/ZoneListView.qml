import QtQuick
import QtQuick.Controls


ListView {
  id: zoneListView

  property alias zoneListModel: zoneListModel

  signal zoneChecked(string zoneName)
  signal zoneUnchecked(string zoneName)

  focus: true
  orientation: Qt.Vertical

  model: ListModel {
    id: zoneListModel
  }

  delegate: CheckBox {
    text: name
    onClicked:
    {
        if(checkState === Qt.UnChecked)
        {
            zoneListView.zoneUnchecked(text);
        }
        else if(checkState === Qt.Checked)
        {
            zoneListView.zoneChecked(text);
        }
    }
  }
}
