#ifndef H_NODE_EDITOR_WORKSPACE_PRIVATE
#define H_NODE_EDITOR_WORKSPACE_PRIVATE

#include <Workspace.h>
#include <QUndoStack>

NODE_EDITOR_BEGIN_NAMESPACE

struct Workspace::Private
{
    EdgeList edges;
    QUndoStack undoStack;
};

NODE_EDITOR_END_NAMESPACE

#endif
