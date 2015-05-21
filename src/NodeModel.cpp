#include <NodeModel.h>

NODE_EDITOR_BEGIN_NAMESPACE

NodeModel::NodeModel(QObject *parent) : QAbstractListModel(parent)
{
}

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > mNodes.count())
        return QVariant();

    const Node &node = mNodes[index.row()];

    if(role == LeftRole)
        return node.x;

    if(role == TopRole)
        return node.y;

    return QVariant();
}

int NodeModel::rowCount(const QModelIndex &parent) const
{
    return mNodes.size();
}

void NodeModel::add(const Node &node)
{
    mNodes.append(node);
}

QHash<int, QByteArray> NodeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TopRole] = "top";
    roles[LeftRole] = "left";
    return roles;
}

NODE_EDITOR_END_NAMESPACE
