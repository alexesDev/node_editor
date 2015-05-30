#ifndef H_NODE_EDITOR_SERVER
#define H_NODE_EDITOR_SERVER

#include <QObject>
#include <pimpl.h>

struct Workspace;

struct ServerEndPoint
{
    QString sender;
    QString receiver;
};

class Server : public QObject
{
    Q_OBJECT
    PIMPL_PRIVATE_DATA

    public:
        Server(const ServerEndPoint &endPoint, Workspace *workspace, QObject *parent = nullptr);
        ~Server();

    public slots:
        void run();

    private:
};

#endif
