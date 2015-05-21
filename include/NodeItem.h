#ifndef H_NODE_EDITOR_NODE_ITEM
#define H_NODE_EDITOR_NODE_ITEM

#include <namespace.h>
#include <Input.h>
#include <Output.h>
#include <QList>

NODE_EDITOR_BEGIN_NAMESPACE

class NodeImplementation;

struct NodeItem
{
    NodeImplementation *implementation;
    QList<Input*> inputs;
    QList<Output*> outputs;
};

NODE_EDITOR_END_NAMESPACE

#endif
