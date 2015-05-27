#include <Workspace.h>
#include <iostream>
#include <NodeModel.h>
#include <QApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QUndoStack>

int main(int argc, char **argv)
{
    Workspace w;

    QApplication app(argc, argv);
    //NodeEditor::NodeModel model;
    //model.add(NodeEditor::Node{ 100, 100 });
    //model.add(NodeEditor::Node{ 100, 250 });

    qmlRegisterType<Node>("Editor", 1, 0, "Node");
    qmlRegisterType<QUndoStack>("Editor", 1, 0, "UndoStack");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *context = view.rootContext();

    context->setContextProperty("workspace", &w);
    view.setSource(QUrl("../ui/main.qml"));
    view.show();

    return app.exec();
}
