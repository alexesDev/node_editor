#include <Connection.h>

Connection::Connection(Node *source, Node *sink, QObject *parent) :
    QObject(parent),
    mSource(source),
    mSink(sink)
{
}

Node *Connection::source() const
{
    return mSource;
}

Node *Connection::sink() const
{
    return mSink;
}
