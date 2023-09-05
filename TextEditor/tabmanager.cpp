#include "tabmanager.h"

TabManager::TabManager(QTabWidget* parent) : QTabWidget(parent)
{

}
void TabManager::ReadFile(QString filename)
{
    QFile file(filename);
    QString line;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream (&file);
        while(!stream.atEnd())
        {
            line = stream.readLine();
            qDebug()<<line;
        }
    }

}

