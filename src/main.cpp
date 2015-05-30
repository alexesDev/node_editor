#include <Workspace.h>
#include <functional>
#include <LiveReload.h>
#include <QQuickView>
#include <QQmlContext>
#include <QUndoStack>
#include <Connection.h>
#include <Node.h>
#include <Pin.h>
#include <Console.h>
#include <QtGlobal>
#include <QThread>
#include <Server.h>

static Workspace w;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message)
{
    w.console()->addMessage(message);
}

int main(int argc, char **argv)
{
    qInstallMessageHandler(messageHandler);

    LiveReload app(argc, argv);

    qmlRegisterType<Node>("Editor", 1, 0, "Node");
    qmlRegisterType<QUndoStack>("Editor", 1, 0, "UndoStack");
    qmlRegisterType<Connection>("Editor", 1, 0, "Connection");
    qmlRegisterType<Pin>("Editor", 1, 0, "Pin");
    qmlRegisterType<Console>("Editor", 1, 0, "Console");

    app.view.rootContext()->setContextProperty("workspace", &w);
    app.view.setSource(QUrl("../ui/main.qml"));
    app.view.show();

    Server server({ "tcp://127.0.0.1:4242", "tcp://127.0.0.1:4243" }, &w);
    QThread serverThread;

    server.connect(&serverThread, &QThread::started, &server, &Server::run);
    serverThread.start();

    return app.exec();
}
