#include <Console.h>

NODE_EDITOR_BEGIN_NAMESPACE

Console::Console(QObject *parent) :
    QObject(parent)
{
    mLines << "Launch" << "Load nodes" << "Detect circle" << "Create new node" << "Processing... 50%";
}

QStringList Console::lines()
{
    return mLines;
}

NODE_EDITOR_END_NAMESPACE