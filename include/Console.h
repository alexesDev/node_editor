#ifndef H_NODE_EDITOR_CONSOLE
#define H_NODE_EDITOR_CONSOLE

#include <QObject>
#include <QQmlListProperty>

class Console : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList lines READ lines NOTIFY linesChanged)

    public:
        Console(QObject *parent = nullptr);

        QStringList &lines();
        void addMessage(const QString &value);

    signals:
        void linesChanged();

    private:
        QStringList mLines;
};

#endif
