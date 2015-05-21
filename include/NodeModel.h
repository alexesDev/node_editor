#ifndef H_NODE_EDITOR_NODE_MODEL
#define H_NODE_EDITOR_NODE_MODEL

#include <namespace.h>
#include <QAbstractListModel>
#include <Node.h>

NODE_EDITOR_BEGIN_NAMESPACE

class NodeModel : public QAbstractListModel
{
    Q_OBJECT

    public:
        NodeModel(QObject *parent = nullptr);

        enum Roles
        {
            LeftRole = Qt::UserRole + 1,
            TopRole = Qt::UserRole + 2
        };

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        int rowCount(const QModelIndex &parent) const;
        QHash<int, QByteArray> roleNames() const;

        void add(const Node &node);

    private:
        QList<Node> mNodes;
};

NODE_EDITOR_END_NAMESPACE

#endif
