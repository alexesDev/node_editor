import QtQuick 2.2

Item {
  width: 10
  height: 10

  x: -width / 2
  y: model.index * 25

  Pin { }
}
