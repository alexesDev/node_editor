#include <Workspace.h>
#include <WorkspacePrivate.h>

NODE_EDITOR_BEGIN_NAMESPACE

Workspace::Workspace() : d(new Private)
{
    d->edges.push_back(std::make_pair(0, 2));
    d->edges.push_back(std::make_pair(1, 2));
    d->edges.push_back(std::make_pair(2, 3));
}

Workspace::~Workspace()
{
}

NODE_EDITOR_END_NAMESPACE
