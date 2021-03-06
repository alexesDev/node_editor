import QtQuick 2.2

Item {
  property var rootModel : model
  property int pinSize

  Pin {
    model: rootModel
    width: pinSize
    height: pinSize
    x: -pinSize / 2
  }

  Rectangle {
    x: 10
    height: 20
    width: parent.width - 20
    radius: 3
    border.color: 'black'
    color: '#5A5A5A'

    Text {
      anchors.fill: parent
      text: 'Demo control'
      font.pointSize: 8
      verticalAlignment: Text.AlignVCenter
      horizontalAlignment: Text.AlignHCenter
    }
  }
}
