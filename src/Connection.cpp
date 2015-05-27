#include <Connection.h>
#include <Node.h>

Connection::Connection(Node *source, int sourceIndex, Node *sink, int sinkIndex, QObject *parent) :
    QObject(parent),
    mSource(source),
    mSink(sink),
    mSourceIndex(sourceIndex),
    mSinkIndex(sinkIndex)
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

int Connection::sourceIndex() const
{
    return mSourceIndex;
}

int Connection::sinkIndex() const
{
    return mSinkIndex;
}
