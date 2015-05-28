#ifndef H_NODE_EDITOR_WORKSPACE
#define H_NODE_EDITOR_WORKSPACE

#include <vector>
#include <pimpl.h>
#include <namespace.h>
#include <QObject>
#include <QQmlListProperty>

class QUndoStack;

NODE_EDITOR_BEGIN_NAMESPACE

class Node;
class Connection;
class Pin;

struct Workspace : public QObject
{
    typedef unsigned int EdgeId;
    typedef std::pair<EdgeId, EdgeId> Edge;
    typedef std::vector<Edge> EdgeList;

    Workspace();
    ~Workspace();

    bool hasCircle() const;
    QUndoStack *undoStack() const;

    QQmlListProperty<Node> nodesAsObjects();
    QQmlListProperty<Connection> qmlConnections();

    PIMPL_PRIVATE_DATA
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Node> nodes READ nodesAsObjects NOTIFY nodesChanged)
    Q_PROPERTY(QQmlListProperty<Connection> connections READ qmlConnections NOTIFY connectionsChanged)
    Q_PROPERTY(QUndoStack *undoStack READ undoStack NOTIFY undoStackChanged)

    QList<Node*> mNodes; // todo: move to private class
    QList<Connection*> mConnections;

    public slots:
        void moveNode(int index, const QPointF &position);
        void createConnection(Pin *from, Pin *to);

    signals:
        void nodesChanged();
        void undoStackChanged();
        void connectionsChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
