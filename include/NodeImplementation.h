#ifndef H_NODE_EDITOR_NODE_IMPLEMENTATION
#define H_NODE_EDITOR_NODE_IMPLEMENTATION

#include <namespace.h>
#include <QString>

NODE_EDITOR_BEGIN_NAMESPACE

class Node;

class NodeImplementation
{
    public:
        virtual void createPins(Node *node) = 0;
        virtual const QString &name() const = 0;
};

NODE_EDITOR_END_NAMESPACE

#endif
