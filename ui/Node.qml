import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
  id: root
  width: 100
  height: 100

  x: model.x
  y: model.y

  Drag.active: dragArea.drag.active
  Drag.onDragFinished: console.log('onDragFinished')

  Rectangle {
    id: container
    color: '#5A5A5A'
    anchors.fill: parent
    radius: 3
  }

  MouseArea {
    id: dragArea
    anchors.fill: parent
    drag.target: parent
    drag.threshold: 0
    onReleased: workspace.moveNode(index, Qt.point(root.x, root.y));
  }
}
