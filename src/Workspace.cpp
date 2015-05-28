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
    node2->setY(100);
    node2->outputPin(0);
    node2->outputPin(1);

    auto node3 = new Node();
    node3->setX(100);
    node3->setY(250);

    mNodes.append(node1);
    mNodes.append(node2);
    mNodes.append(node3);

    auto connection1 = new Connection(node1->outputPin(0), node2->inputPin(0), this);
    mConnections.append(connection1);

    auto connection2 = new Connection(node1->outputPin(1), node2->inputPin(2), this);
    mConnections.append(connection2);

    auto connection3 = new Connection(node3->outputPin(0), node2->inputPin(1), this);
    mConnections.append(connection3);
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
