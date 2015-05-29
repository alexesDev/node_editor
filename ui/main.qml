import QtQuick 2.2
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
  id: root

  color: '#393939'
  focus: true

  SplitView {
    anchors.fill: parent
    orientation: Qt.Vertical

    handleDelegate: Rectangle {
      width: 1
      height: 1
      color: '#555'
    }

    Workspace {
      Layout.fillHeight: true
      height: 100
    }

    Console {
      height: 60
    }
  }

  Keys.onPressed: {
    if(event.matches(StandardKey.Undo))
      workspace.undoStack.undo();
    else if(event.matches(StandardKey.Redo))
      workspace.undoStack.redo();
  }
}
