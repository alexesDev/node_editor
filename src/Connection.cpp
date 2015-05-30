#include <Connection.h>
#include <Pin.h>
#include <Node.h>

Connection::Connection(Pin *source, Pin *sink, QObject *parent) :
    QObject(parent),
    mSource(source),
    mSink(sink)
{
    connect(mSource->node(), &Node::xChanged, this, &Connection::sourceChanged);
    connect(mSource->node(), &Node::yChanged, this, &Connection::sourceChanged);

    connect(mSink->node(), &Node::xChanged, this, &Connection::sinkChanged);
    connect(mSink->node(), &Node::yChanged, this, &Connection::sinkChanged);

    if(mSource->node()->isInputPin(mSource))
        std::swap(mSource, mSink);
}

Pin *Connection::source() const
{
    return mSource;
}

Pin *Connection::sink() const
{
    return mSink;
}
