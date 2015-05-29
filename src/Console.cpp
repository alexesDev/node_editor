#include <Console.h>

NODE_EDITOR_BEGIN_NAMESPACE

Console::Console(QObject *parent) :
    QObject(parent)
{
    mLines << "Default undo/redo shortcuts works.";
}

void Console::addMessage(const QString &value)
{
    mLines << value;
    emit linesChanged();
}

QStringList &Console::lines()
{
    return mLines;
}

NODE_EDITOR_END_NAMESPACE
