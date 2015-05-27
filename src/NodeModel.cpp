#include <NodeModel.h>
#include <QDebug>

NODE_EDITOR_BEGIN_NAMESPACE

NodeModel::NodeModel(QObject *parent) : QAbstractListModel(parent)
{
    qDebug() << Qt::UserRole;
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

bool NodeModel::setDataForRow(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "setData";

    if(!index.isValid())
        return false;

    auto &node = mNodes[index.row()];
    bool ok = false;

    if(role == LeftRole)
    {
        node.x = value.toInt(&ok);
        qDebug() << "change x";
    }
    else if(role == TopRole)
        node.y = value.toInt(&ok);

    if(ok)
        emit dataChanged(index, index);

    return ok;
}

Qt::ItemFlags NodeModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable;
}

int NodeModel::rowCount(const QModelIndex &parent) const
{
    return mNodes.size();
}

void NodeModel::add(const Node &node)
{
    mNodes.append(node);
    emit dataChanged(createIndex(0,0), createIndex(mNodes.size(), 0));
}

QHash<int, QByteArray> NodeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TopRole] = "top";
    roles[LeftRole] = "left";
    return roles;
}

NODE_EDITOR_END_NAMESPACE
