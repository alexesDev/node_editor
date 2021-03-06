#include <ConnectCommand.h>
#include <Pin.h>
#include <Connection.h>

ConnectCommand::ConnectCommand(QList<Connection*> &connections, std::function<void()> changeCallback, Pin *from, Pin *to, QUndoCommand *parent) :
    QUndoCommand(parent),
    mConnections(connections),
    mChangeCallback(changeCallback),
    mConnection(nullptr),
    mFrom(from),
    mTo(to)
{
}

void ConnectCommand::undo()
{
    mConnections.removeOne(mConnection);
    delete mConnection;
    mConnection = nullptr;
    mChangeCallback();
}

void ConnectCommand::redo()
{
    mConnection = new Connection(mFrom, mTo);
    mConnections.append(mConnection); // need set parent
    mChangeCallback();
}
