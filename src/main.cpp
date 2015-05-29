#include <Workspace.h>
#include <iostream>
#include <LiveReload.h>
#include <QQuickView>
#include <QQmlContext>
#include <QUndoStack>
#include <Connection.h>
#include <Node.h>
#include <Pin.h>

int main(int argc, char **argv)
{
    LiveReload app(argc, argv);
    Workspace w;

    qmlRegisterType<Node>("Editor", 1, 0, "Node");
    qmlRegisterType<QUndoStack>("Editor", 1, 0, "UndoStack");
    qmlRegisterType<Connection>("Editor", 1, 0, "Connection");
    qmlRegisterType<Pin>("Editor", 1, 0, "Pin");

    app.view.rootContext()->setContextProperty("workspace", &w);
    app.view.setSource(QUrl("../ui/main.qml"));
    app.view.show();

    return app.exec();
}
