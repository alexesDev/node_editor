#include <Workspace.h>
#include <iostream>
#include <NodeModel.h>
#include <QApplication>
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char **argv)
{
    NodeEditor::Workspace w;
    std::cout << w.hasCircle() << std::endl;

    QApplication app(argc, argv);
    NodeEditor::NodeModel model;
    model.add(NodeEditor::Node{ 100, 100 });
    model.add(NodeEditor::Node{ 100, 250 });

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *context = view.rootContext();
    context->setContextProperty("nodes", &model);
    view.setSource(QUrl("../ui/main.qml"));
    view.show();

    return app.exec();
}
