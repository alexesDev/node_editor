#ifndef H_NODE_EDITOR_MOVE_COMMAND
#define H_NODE_EDITOR_MOVE_COMMAND

#include <namespace.h>
#include <QUndoCommand>

NODE_EDITOR_BEGIN_NAMESPACE

class Node;

class MoveCommand : public QUndoCommand
{
    public:
        MoveCommand(Node *node, int left, int top, QUndoCommand *parent = nullptr);

        void undo();
        void redo();

    private:
        int mLeft, mNewLeft;
        int mTop, mNewTop;
        Node *mNode;
};

NODE_EDITOR_END_NAMESPACE

#endif
