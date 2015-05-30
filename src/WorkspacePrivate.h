#ifndef H_NODE_EDITOR_WORKSPACE_PRIVATE
#define H_NODE_EDITOR_WORKSPACE_PRIVATE

#include <Workspace.h>
#include <Console.h>
#include <QUndoStack>

struct Workspace::Private
{
    EdgeList edges;
    QUndoStack undoStack;
    Console console;
};

#endif
