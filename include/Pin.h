#ifndef H_NODE_EDITOR_PIN
#define H_NODE_EDITOR_PIN

#include <QObject>

class Node;

class Pin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Node *node READ node NOTIFY nodeChanged)
    Q_PROPERTY(int index READ index NOTIFY indexChanged)

    Node *mNode;
    int mIndex;

    public:
        Pin(Node *node = nullptr, int index = 0, QObject *parent = nullptr);

        Node *node() const;
        int index() const;

    signals:
        void nodeChanged();
        void indexChanged();
};

#endif
