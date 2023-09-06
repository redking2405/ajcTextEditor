#ifndef NEWTAB_H
#define NEWTAB_H

#include <QWidget>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include "mytextedit.h"

namespace Ui {
class newtab;
}

class newtab : public QWidget
{
    Q_OBJECT

public:
    explicit newtab(QWidget *parent = nullptr);
    ~newtab();
    void ShowFile(QFile*  file);
    void SaveFile(QFile* file);
    bool hasUnsavedChange;
    QString name;

public slots:
    void Update();
private slots:
    void UpdateCursor();
private:
    Ui::newtab *ui;
    bool fileOpened;
};

#endif // NEWTAB_H
