import QtQuick 2.2

Item {
  id: root

  property var model
  property color primaryColor: '#666'
  property color hoverColor: '#999'

  Rectangle {
    id: view
    color: primaryColor
    border.color: '#000'
    border.width: 1
    radius: width
    x: root.width / 4
    y: root.height / 4
    width: root.width / 2
    height: root.height / 2
  }

  MouseArea {
    id: mouseArea
    anchors.fill: parent
    hoverEnabled: true
    drag.target: tile
    drag.threshold: 0
    cursorShape: Qt.PointingHandCursor

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
      when: mouseArea.containsMouse
      PropertyChanges {
        target: view
        color: hoverColor
      }
    },

    State {
      when: dragTarget.containsDrag
      PropertyChanges {
        target: view
        color: '#0f0'
      }
    }
  ]
}
