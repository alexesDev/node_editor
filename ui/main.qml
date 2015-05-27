import QtQuick 2.2

Rectangle {
  color: '#393939'
  focus: true

  ConnectionCanvas {
    anchors.fill: parent
    model: workspace.connections
  }

  Repeater {
    anchors.fill: parent
    model: workspace.nodes

    delegate: Node { }
  }

  Keys.onPressed: {
    if(event.matches(StandardKey.Undo))
      workspace.undoStack.undo();
    else if(event.matches(StandardKey.Redo))
      workspace.undoStack.redo();
  }
}
