#include <Pin.h>

Pin::Pin(Node *node, int index, QObject *parent) :
    QObject(parent),
    mNode(node),
    mIndex(index)
{
}

Node *Pin::node() const
{
    return mNode;
}

int Pin::index() const
{
    return mIndex;
}
