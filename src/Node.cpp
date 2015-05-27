#include <Node.h>
#include <QDebug>

NODE_EDITOR_BEGIN_NAMESPACE

Node::Node(QObject *parent) : QObject(parent)
{
}

int Node::x() const
{
    return mX;
}

int Node::y() const
{
    return mY;
}

void Node::Node::setX(int value)
{
    mX = value;
    emit xChanged();
}

void Node::setY(int value)
{
    mY = value;
    emit yChanged();
}

NODE_EDITOR_END_NAMESPACE
