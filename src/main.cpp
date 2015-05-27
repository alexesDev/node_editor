#include <Workspace.h>
#include <iostream>
#include <QApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QUndoStack>
#include <Connection.h>
#include <Node.h>
#include <Pin.h>

int main(int argc, char **argv)
{
    Workspace w;

    QApplication app(argc, argv);

    qmlRegisterType<Node>("Editor", 1, 0, "Node");
    qmlRegisterType<QUndoStack>("Editor", 1, 0, "UndoStack");
    qmlRegisterType<Connection>("Editor", 1, 0, "Connection");
    qmlRegisterType<Pin>("Editor", 1, 0, "Pin");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *context = view.rootContext();

    context->setContextProperty("workspace", &w);
    view.setSource(QUrl("../ui/main.qml"));
    view.show();

    return app.exec();
}
