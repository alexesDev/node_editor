#ifndef H_NODE_EDITOR_CONNECTION
#define H_NODE_EDITOR_CONNECTION

#include <namespace.h>
#include <QObject>

NODE_EDITOR_BEGIN_NAMESPACE

class Pin;

class Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Pin *source READ source NOTIFY sourceChanged)
    Q_PROPERTY(Pin *sink READ sink NOTIFY sinkChanged)

    Pin *mSource;
    Pin *mSink;

    public:
        Connection(Pin *source = nullptr, Pin *sink = nullptr, QObject *parent = 0);

        Pin *source() const;
        Pin *sink() const;

    signals:
        void sourceChanged();
        void sinkChanged();
};

NODE_EDITOR_END_NAMESPACE

#endif
