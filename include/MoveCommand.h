#ifndef H_NODE_EDITOR_MOVE_COMMAND
#define H_NODE_EDITOR_MOVE_COMMAND

#include <QUndoCommand>

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

#endif
