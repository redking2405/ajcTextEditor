#ifndef NEWTAB_H
#define NEWTAB_H

#include <QWidget>
#include <QTextStream>
#include <QFile>
#include <QDebug>

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

public slots:
    void Update();
private:
    Ui::newtab *ui;
};

#endif // NEWTAB_H
