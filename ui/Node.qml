import QtQuick 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.1

Item {
  id: root

  property var rootModel : model;
  property int headerHeight : 25;
  property int controlRowHeight : 25

  width: 150
  height: (rootModel.inputPins.length + rootModel.outputPins.length) * controlRowHeight + headerHeight + 5

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

  NodeHeader {
    text: "Node #" + index
  }

  ColumnLayout {
    x: 0
    y: headerHeight
    spacing: 0

    ListView {
      width: parent.width
      height: rootModel.outputPins.length * 25
      model: rootModel.outputPins
      delegate: OutputPin {
        width: root.width
        height: 25
        pinSize: 20
      }
    }

    ListView {
      width: parent.width
      height: rootModel.inputPins.length * 25
      model: rootModel.inputPins
      delegate: InputPin {
        width: root.width
        height: 25
        pinSize: 20
      }
    }
  }

  MouseArea {
    id: dragArea
    anchors.fill: parent
    drag.target: parent
    drag.threshold: 0
    drag.filterChildren: true

    property point startPosition;

    onPressed: startPosition = Qt.point(root.x, root.y);
    onPositionChanged: { model.x = root.x; model.y = root.y }

    onReleased: {
      // todo: remove this hack for the one-step undo history
      var newPosition = Qt.point(root.x, root.y);

      model.x = startPosition.x
      model.y = startPosition.y

      workspace.moveNode(index, newPosition);
    }
  }
}
