#ifndef H_NODE_EDITOR_LIVE_RELOAD
#define H_NODE_EDITOR_LIVE_RELOAD

#include <QApplication>
#include <QQuickView>
#include <QFileSystemWatcher>

class LiveReload: public QApplication
{
    Q_OBJECT

    public:
        LiveReload(int &argc, char **argv);

        QQuickView view;
        QFileSystemWatcher watcher;

    private slots:
        void fileChanged(const QString &path);
};

#endif
