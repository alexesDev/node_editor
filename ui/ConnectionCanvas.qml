import QtQuick 2.2

Canvas {
  id: canvas

  property var model;

  function connectToNodePositions(){
    for(var i = 0; i < model.length; i += 1){
      var connection = model[i];
      connection.sourceChanged.connect(requestPaint);
      connection.sinkChanged.connect(requestPaint);
    }
  }

  Component.onCompleted: {
    workspace.connectionsChanged.connect(function(){
      connectToNodePositions(); // todo: remove double connections
      requestPaint();
    });

    connectToNodePositions();
  }

  onPaint: {
    var ctx = canvas.getContext('2d');
    ctx.clearRect(0, 0, parent.width, parent.height);

    for(var i = 0; i < model.length; i += 1){
      var connection = model[i];
      var nodeWidth = 100;
      var pinPadding = 25;
      var headerHeight = 30;

      var x1 = connection.source.node.x + nodeWidth;
      var y1 = connection.source.node.y + headerHeight +
        pinPadding * connection.source.index + 7; // todo: remove a magic number 5

      var x2 = connection.sink.node.x;
      var y2 = connection.sink.node.y + headerHeight +
        connection.sink.node.outputPins.length * pinPadding +
        connection.sink.index * pinPadding + 10; // todo: remove a magic number 10

      var linePadding = Math.abs(x1 - x2) * 0.5;

      ctx.beginPath();
      ctx.moveTo(x1, y1);
      ctx.bezierCurveTo(x1 + linePadding, y1, x2 - linePadding, y2, x2, y2);
      ctx.stroke();
    }
  }
}
