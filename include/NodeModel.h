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

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        Q_INVOKABLE bool setDataForRow(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
        int rowCount(const QModelIndex &parent) const override;
        Qt::ItemFlags flags(const QModelIndex &index) const override;
        QHash<int, QByteArray> roleNames() const override;

    public slots:
        void add(const Node &node);

    private:
        QList<Node> mNodes;
};

NODE_EDITOR_END_NAMESPACE

#endif
