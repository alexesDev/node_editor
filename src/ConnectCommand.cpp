#include <ConnectCommand.h>
#include <Pin.h>
#include <Connection.h>
#include <QDebug>

NODE_EDITOR_BEGIN_NAMESPACE

ConnectCommand::ConnectCommand(QList<Connection*> &connections, std::function<void()> changeCallback, Pin *from, Pin *to, QUndoCommand *parent) :
    QUndoCommand(parent),
    mConnections(connections),
    mChangeCallback(changeCallback),
    mFrom(from),
    mTo(to)
{
}

void ConnectCommand::undo()
{
}

void ConnectCommand::redo()
{
    mConnections.append(new Connection(mFrom, mTo)); // need set parent
    mChangeCallback();
}

NODE_EDITOR_END_NAMESPACE
