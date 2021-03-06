#include <Node.h>
#include <Pin.h>

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
    for(auto pin : mInputPins)
        if(pin->index() == index)
            return pin;

    auto pin = new Pin(this, index, this);
    mInputPins.insert(index, pin);
    emit inputPinsChanged();
    return pin;
}

Pin *Node::outputPin(int index)
{
    for(auto pin : mOutputPins)
        if(pin->index() == index)
            return pin;

    auto pin = new Pin(this, index, this);
    mOutputPins.insert(index, pin);
    emit outputPinsChanged();
    return pin;
}

bool Node::isInputPin(Pin* pin) const
{
    return mInputPins.contains(pin);
}

bool Node::isOutputPin(Pin* pin) const
{
    return mOutputPins.contains(pin);
}

QQmlListProperty<Pin> Node::qmlInputPins()
{
    return QQmlListProperty<Pin>(this, mInputPins);
}

QQmlListProperty<Pin> Node::qmlOutputPins()
{
    return QQmlListProperty<Pin>(this, mOutputPins);
}
