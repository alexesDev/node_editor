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
    Q_PROPERTY(int sourceIndex READ sourceIndex NOTIFY sourceIndexChanged)
    Q_PROPERTY(int sinkIndex READ sinkIndex NOTIFY sinkIndexChanged)

    Node *mSource;
    Node *mSink;

    int mSourceIndex;
    int mSinkIndex;

    public:
        Connection(Node *source = nullptr, int sourceIndex = 0, Node *sink = nullptr, int sinkIndex = 0, QObject *parent = 0);

        Node *source() const;
        Node *sink() const;

        int sourceIndex() const;
        int sinkIndex() const;

    signals:
        void sourceChanged();
        void sinkChanged();
        void sourceIndexChanged();
        void sinkIndexChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
