import QtQuick 2.0

Rectangle {
  color: 'black'

  Repeater {
    anchors.fill: parent
    model: nodes

    delegate: Rectangle {
      x: model.left
      y: model.top
      width: 100
      height: 100
      color: 'red'
    }
  }
}
