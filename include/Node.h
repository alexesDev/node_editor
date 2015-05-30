#ifndef H_NODE_EDITOR_NODE
#define H_NODE_EDITOR_NODE

#include <QObject>
#include <QQmlListProperty>

class Pin;

class Node : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(QQmlListProperty<Pin> inputPins READ qmlInputPins NOTIFY inputPinsChanged)
    Q_PROPERTY(QQmlListProperty<Pin> outputPins READ qmlOutputPins NOTIFY outputPinsChanged)

    int mX;
    int mY;

    QList<Pin*> mInputPins;
    QList<Pin*> mOutputPins;

    public:
        Node(QObject *parent = nullptr);

        int x() const;
        int y() const;

        void setX(int value);
        void setY(int value);

        Pin* inputPin(int index); // todo: rename to sourcePin
        Pin* outputPin(int index); // todo: rename to sinkPin

        Q_INVOKABLE bool isInputPin(Pin* pin) const;
        Q_INVOKABLE bool isOutputPin(Pin* pin) const;

        QQmlListProperty<Pin> qmlInputPins();
        QQmlListProperty<Pin> qmlOutputPins();

    signals:
        void xChanged();
        void yChanged();
        void inputPinsChanged();
        void outputPinsChanged();
};

#endif
