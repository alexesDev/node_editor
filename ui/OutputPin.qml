import QtQuick 2.2

Item {
  id: root

  property var rootModel : model
  property int pinSize

  Text {
    width: parent.width - 10
    height: parent.height
    text: 'Output label'
    horizontalAlignment: Text.AlignRight
    verticalAlignment: Text.AlignVCenter
  }

  Pin {
    model: rootModel
    width: pinSize
    height: pinSize
    x: root.width
    y: 7
  }
}
