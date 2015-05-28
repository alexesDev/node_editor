import QtQuick 2.2
import QtGraphicalEffects 1.0

Item {
  id: root
  width: 100
  height: 100

  x: model.x
  y: model.y

  property var rootModel : model;

  Drag.active: dragArea.drag.active
  Drag.onDragFinished: console.log('onDragFinished')

  Rectangle {
    id: container
    color: '#5A5A5A'
    anchors.fill: parent
    radius: 3
  }

  Rectangle {
    id: header
    color: '#2A2A2A'
    width: root.width
    height: 20
    radius: 3

    Text {
      anchors.fill: parent
      text: "Node"
      color: '#ccc'
      font.pointSize: 9
      verticalAlignment: Text.AlignVCenter
      horizontalAlignment: Text.AlignHCenter
    }
  }

  Item {
    x: 0
    y: 25

    Repeater {
      model: rootModel.inputPins
      delegate: InputPin { }
    }
  }

  Item {
    x: root.width
    y: 25

    Repeater {
      model: rootModel.outputPins
      delegate: OutputPin { }
    }
  }

  MouseArea {
    id: dragArea
    anchors.fill: parent
    drag.target: parent
    drag.threshold: 0

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
