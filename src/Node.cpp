#include <Node.h>
#include <Pin.h>

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

Pin *Node::inputPin(int index)
{
    if(mInputPins.contains(index))
        return mInputPins[index];
    else
    {
        auto pin = new Pin(this, index, this);
        mInputPins.insert(index, pin);
        return pin;
    }
}

Pin *Node::outputPin(int index)
{
    if(mOutputPins.contains(index))
        return mInputPins[index];
    else
    {
        auto pin = new Pin(this, index, this);
        mOutputPins.insert(index, pin);
        return pin;
    }
}

NODE_EDITOR_END_NAMESPACE
