#ifndef H_NODE_EDITOR_NODE_ITEM_MODEL
#define H_NODE_EDITOR_NODE_ITEM_MODEL

#include <namespace.h>
#include <NodeItem.h>
#include <QList>
#include <QAbstractItemModel>

NODE_EDITOR_BEGIN_NAMESPACE

class NodeItemModel : public QAbstractItemModel
{
    Q_OBJECT
    QList<NodeItem*> mItems;

    public:
        explicit NodeItemModel(QObject *parent = nullptr);

        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role) const;
};

NODE_EDITOR_END_NAMESPACE

#endif
