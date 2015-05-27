#include <Pin.h>

NODE_EDITOR_BEGIN_NAMESPACE

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

NODE_EDITOR_BEGIN_NAMESPACE
