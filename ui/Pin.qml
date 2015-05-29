import QtQuick 2.2

Rectangle {
  id: root

  property var model

  anchors.fill: parent
  color: '#666'
  radius: parent.width
  border.color: '#000'
  border.width: 1

  width: 10
  height: 10

  MouseArea {
    id: mouseArea
    anchors.fill: parent
    drag.target: tile

    Rectangle {
      id: tile
      width: root.width
      height: root.height
      color: '#666'
      radius: parent.width
      border.color: '#000'
      border.width: 1
      visible: false

      Drag.keys: ["pin"]
      Drag.active: mouseArea.drag.active
    }

    property point startPosition;

    onPressed: {
      startPosition = Qt.point(tile.x, tile.y)
      tile.visible = true
    }

    onReleased: {
      tile.x = startPosition.x
      tile.y = startPosition.y
      tile.visible = false

      if(tile.Drag.target !== null)
        workspace.createConnection(model.modelData, tile.Drag.target.pinModel.modelData);
    }
  }

  DropArea {
    id: dragTarget
    anchors.fill: parent
    keys: ["pin"]

    property var pinModel : root.model
  }

  states: [
    State {
      when: dragTarget.containsDrag
      PropertyChanges {
        target: root
        color: '#0f0'
      }
    }
  ]
}
