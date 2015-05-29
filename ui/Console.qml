import QtQuick 2.2

Rectangle {
  color: '#222'

  property int padding : 5

  ListView {
    id: messageList
    x: padding
    y: padding
    width: parent.width - padding * 2
    height: parent.height - padding * 2
    model: ["Launch", "Load nodes", "Detect circle", "Create new node", "Processing... 50%"]
    spacing: padding

    Component.onCompleted: messageList.positionViewAtEnd()

    delegate: Text {
      color: '#ccc'
      text: model.modelData
    }
  }
}
