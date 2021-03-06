import QtQuick 2.2

Rectangle {
  id: header
  color: '#2A2A2A'
  width: root.width
  height: 20
  radius: 3

  property string text: "Node"

  Text {
    anchors.fill: parent
    text: header.text
    color: '#ccc'
    font.pointSize: 8
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter
  }
}
