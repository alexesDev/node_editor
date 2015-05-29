import QtQuick 2.2

Item {
  ConnectionCanvas {
    anchors.fill: parent
    model: workspace.connections
  }

  Repeater {
    anchors.fill: parent
    model: workspace.nodes

    delegate: Node { }
  }
}
