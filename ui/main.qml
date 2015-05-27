import QtQuick 2.2

Rectangle {
  color: '#393939'
  focus: true

  Canvas {
    id: canvas
    anchors.fill: parent

    Component.onCompleted: {
      for(var i = 0; i < workspace.connections.length; i += 1){
        var connection = workspace.connections[i];
        connection.sourceChanged.connect(requestPaint);
        connection.sinkChanged.connect(requestPaint);
      }
    }

    onPaint: {
      var ctx = canvas.getContext('2d');
      ctx.clearRect(0, 0, parent.width, parent.height);

      for(var i = 0; i < workspace.connections.length; i += 1){
        var connection = workspace.connections[i];
        var source = connection.source;
        var sink = connection.sink;

        var nodeWidth = 100;
        var pinPadding = 10;

        var x1 = source.x + nodeWidth;
        var y1 = source.y + pinPadding;

        var x2 = sink.x;
        var y2 = sink.y + pinPadding;

        var linePadding = 100;

        ctx.beginPath();
        ctx.moveTo(x1, y1);
        ctx.bezierCurveTo(x1 + linePadding, y1, x2 - linePadding, y2, x2, y2);
        ctx.stroke();
      }
    }
  }

  Repeater {
    anchors.fill: parent
    model: workspace.nodes

    delegate: Node { }
  }

  Keys.onPressed: {
    if(event.matches(StandardKey.Undo))
      workspace.undoStack.undo();
    else if(event.matches(StandardKey.Redo))
      workspace.undoStack.redo();
  }
}
