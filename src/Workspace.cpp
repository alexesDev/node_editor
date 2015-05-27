#include <Workspace.h>
#include <WorkspacePrivate.h>
#include <Connection.h>
#include <Node.h>
#include <QPointF>
#include <MoveCommand.h>

NODE_EDITOR_BEGIN_NAMESPACE

Workspace::Workspace() : d(new Private)
{
    d->edges.push_back(std::make_pair(0, 2));
    d->edges.push_back(std::make_pair(1, 2));
    d->edges.push_back(std::make_pair(2, 3));

    auto node1 = new Node();
    node1->setX(100);
    node1->setY(100);

    auto node2 = new Node();
    node2->setX(500);
    node2->setY(150);

    mNodes.append(node1);
    mNodes.append(node2);

    auto connection1 = new Connection(node1, node2, this);
    mConnections.append(connection1);
}

Workspace::~Workspace()
{
}

QUndoStack *Workspace::undoStack() const
{
    return &d->undoStack;
}

void Workspace::moveNode(int index, const QPointF &position)
{
    d->undoStack.push(new MoveCommand(mNodes[index], position.x(), position.y()));
}

QQmlListProperty<Node> Workspace::nodesAsObjects()
{
    return QQmlListProperty<Node>(this, mNodes);
}

QQmlListProperty<Connection> Workspace::qmlConnections()
{
    return QQmlListProperty<Connection>(this, mConnections);
}

NODE_EDITOR_END_NAMESPACE
