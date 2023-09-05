#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QTabWidget>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
//#include "mainwindow.h"

class TabManager : public QTabWidget
{
public:
    TabManager(QTabWidget* parent= nullptr);
    void OpenFile();
    void ReadFile(QString filename);
};

#endif // TABMANAGER_H
