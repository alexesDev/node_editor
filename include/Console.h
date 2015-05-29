#ifndef H_NODE_EDITOR_CONSOLE
#define H_NODE_EDITOR_CONSOLE

#include <namespace.h>
#include <QObject>
#include <QQmlListProperty>

NODE_EDITOR_BEGIN_NAMESPACE

class Console : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList lines READ lines NOTIFY linesChanged)

    public:
        Console(QObject *parent = nullptr);

        QStringList lines();

    signals:
        void linesChanged();

    private:
        QStringList mLines;
};

NODE_EDITOR_END_NAMESPACE

#endif
