#include <LiveReload.h>
#include <QThread>
#include <QQmlEngine>

LiveReload::LiveReload(int &argc, char **argv) :
    QApplication(argc, argv)
{
    watcher.addPath("../ui/");
    watcher.addPath("../ui/main.qml"); // todo: move to constant

    connect(&watcher, &QFileSystemWatcher::directoryChanged, this, &LiveReload::fileChanged);
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &LiveReload::fileChanged);

    view.setResizeMode(QQuickView::SizeRootObjectToView);
}

void LiveReload::fileChanged(const QString &path)
{
    view.engine()->clearComponentCache();
    QThread::msleep(50);
    view.setSource(QUrl("../ui/main.qml"));
    view.show();
}
