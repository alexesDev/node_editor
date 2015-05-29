import QtQuick 2.2

Rectangle {
  color: '#393939'
  focus: true

  Workspace {
    anchors.fill: parent
  }

  Keys.onPressed: {
    if(event.matches(StandardKey.Undo))
      workspace.undoStack.undo();
    else if(event.matches(StandardKey.Redo))
      workspace.undoStack.redo();
  }
}
