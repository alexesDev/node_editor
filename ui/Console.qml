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
    model: workspace.console.lines
    spacing: padding

    Component.onCompleted: messageList.positionViewAtEnd()
    onCountChanged: messageList.positionViewAtEnd()

    delegate: Text {
      color: '#ccc'
      text: model.modelData
    }
  }
}
