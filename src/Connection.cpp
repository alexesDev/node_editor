#include <Connection.h>
#include <Node.h>

Connection::Connection(Node *source, Node *sink, QObject *parent) :
    QObject(parent),
    mSource(source),
    mSink(sink)
{
    connect(mSource, &Node::xChanged, this, &Connection::sourceChanged);
    connect(mSource, &Node::yChanged, this, &Connection::sourceChanged);

    connect(mSink, &Node::xChanged, this, &Connection::sinkChanged);
    connect(mSink, &Node::yChanged, this, &Connection::sinkChanged);
}

Node *Connection::source() const
{
    return mSource;
}

Node *Connection::sink() const
{
    return mSink;
}
