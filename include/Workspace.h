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

    PIMPL_PRIVATE_DATA
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Node> nodes READ nodesAsObjects NOTIFY nodesChanged)
    Q_PROPERTY(QUndoStack *undoStack READ undoStack NOTIFY undoStackChanged)
    QList<Node*> mNodes;

    public slots:
        void moveNode(int index, const QPointF &position);

    signals:
        void nodesChanged();
        void undoStackChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
