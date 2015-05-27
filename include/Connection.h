#ifndef H_NODE_EDITOR_CONNECTION
#define H_NODE_EDITOR_CONNECTION

#include <namespace.h>
#include <QObject>

NODE_EDITOR_BEGIN_NAMESPACE

class Node;

class Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Node *source READ source NOTIFY sourceChanged)
    Q_PROPERTY(Node *sink READ sink NOTIFY sinkChanged)

    Node *mSource;
    Node *mSink;

    public:
        Connection(Node *source = nullptr, Node *sink = nullptr, QObject *parent = 0);

        Node *source() const;
        Node *sink() const;

    signals:
        void sourceChanged();
        void sinkChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
