import QtQuick 2.2

Canvas {
  id: canvas

  property var model;

  Component.onCompleted: {
    for(var i = 0; i < model.length; i += 1){
      var connection = model[i];
      connection.sourceChanged.connect(requestPaint);
      connection.sinkChanged.connect(requestPaint);
    }
  }

  onPaint: {
    var ctx = canvas.getContext('2d');
    ctx.clearRect(0, 0, parent.width, parent.height);

    for(var i = 0; i < model.length; i += 1){
      var connection = model[i];
      var nodeWidth = 100;
      var pinPadding = 25;
      var headerHeight = 30;

      var x1 = connection.source.x + nodeWidth;
      var y1 = connection.source.y + pinPadding * connection.sourceIndex + headerHeight;

      var x2 = connection.sink.x;
      var y2 = connection.sink.y + pinPadding * connection.sinkIndex + headerHeight;

      var linePadding = 100;

      ctx.beginPath();
      ctx.moveTo(x1, y1);
      ctx.bezierCurveTo(x1 + linePadding, y1, x2 - linePadding, y2, x2, y2);
      ctx.stroke();
    }
  }
}
