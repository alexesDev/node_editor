#include <MoveCommand.h>
#include <Node.h>

MoveCommand::MoveCommand(Node *node, int left, int top, QUndoCommand *parent) :
    QUndoCommand(parent),
    mNewLeft(left),
    mNewTop(top),
    mNode(node)
{
    mLeft = node->x();
    mTop = node->y();
}

void MoveCommand::undo()
{
    mNode->setX(mLeft);
    mNode->setY(mTop);
}

void MoveCommand::redo()
{
    mNode->setX(mNewLeft);
    mNode->setY(mNewTop);
}
