#ifndef H_NODE_EDITOR_NODE
#define H_NODE_EDITOR_NODE

#include <namespace.h>
#include <QObject>

NODE_EDITOR_BEGIN_NAMESPACE

class Node : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)

    int mX;
    int mY;

    public:
        Node(QObject *parent = nullptr);

        int x() const;
        int y() const;

        void setX(int value);
        void setY(int value);

    signals:
        void xChanged();
        void yChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
