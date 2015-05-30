#include <Server.h>
#include <Workspace.h>
#include <Console.h>
#include <zmqpp.hpp>

struct Server::Private
{
    ServerEndPoint endPoint;
    Workspace *workspace;

    zmqpp::context senderContext;
    zmqpp::socket senderSocket;

    zmqpp::context receiverContext;
    zmqpp::socket receiverSocket;

    Private() :
        senderSocket(senderContext, zmqpp::socket_type::push),
        receiverSocket(receiverContext, zmqpp::socket_type::pull)
    {
    }

    void bind(zmqpp::socket &socket, const QString &name, const QString &endPoint)
    {
        auto console = workspace->console();

        try
        {
            console->addMessage(name + " bind to " + endPoint); // todo: thread safe?
            senderSocket.bind(endPoint.toStdString());
        }
        catch(zmqpp::zmq_internal_exception &e)
        {
            console->addMessage(QString("Exception: ") + e.what());
        }
    }

    void bindSender()
    {
        bind(senderSocket, "Sender", endPoint.sender);
    }

    void bindReceiver()
    {
        bind(receiverSocket, "Receiver", endPoint.receiver);
    }
};

Server::Server(const ServerEndPoint &endPoint, Workspace *workspace, QObject *parent) :
    QObject(parent),
    d(new Private)
{
    d->endPoint = endPoint;
    d->workspace = workspace;
}

Server::~Server()
{
}

void Server::run()
{
    d->bindSender();
    d->bindReceiver();
}
