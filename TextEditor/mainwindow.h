#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QVector>
#include "newtab.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<newtab*> alltabptr;
    static MainWindow* GetMainWindow();
    void UpdateTabName(newtab* currentTab);
public slots:
    void CloseCurrentTab(int i);

private slots:
    void Open();

private:
    Ui::MainWindow *ui;
    void OpenFile();
    void ReadFile(QString filename);
    void AddTab(QString name);
    void SaveTab(int i);
    static MainWindow* mainptr;

};
#endif // MAINWINDOW_H
