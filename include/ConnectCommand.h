#ifndef H_NODE_EDITOR_CONNECT_COMMAND
#define H_NODE_EDITOR_CONNECT_COMMAND

#include <QUndoCommand>
#include <functional>

class Pin;
class Connection;

class ConnectCommand : public QUndoCommand
{
    public:
        ConnectCommand(QList<Connection*> &connections, std::function<void()> changeCallback, Pin *from, Pin *to, QUndoCommand *parent = nullptr);

        void undo();
        void redo();

    private:
        QList<Connection*> &mConnections;
        std::function<void()> mChangeCallback;
        Connection *mConnection;
        Pin *mFrom;
        Pin *mTo;
};

#endif
