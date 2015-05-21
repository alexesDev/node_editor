#ifndef H_NODE_EDITOR_WORKSPACE
#define H_NODE_EDITOR_WORKSPACE

#include <vector>
#include <pimpl.h>
#include <namespace.h>

NODE_EDITOR_BEGIN_NAMESPACE

struct Workspace
{
    typedef unsigned int EdgeId;
    typedef std::pair<EdgeId, EdgeId> Edge;
    typedef std::vector<Edge> EdgeList;

    Workspace();
    ~Workspace();

    bool hasCircle() const;

    PIMPL_PRIVATE_DATA
};

NODE_EDITOR_END_NAMESPACE

#endif
