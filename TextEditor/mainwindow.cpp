#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);
    connect(ui->actionOuvrir, SIGNAL(triggered(bool)), this, SLOT(Open()));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(CloseCurrentTab(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CloseCurrentTab(int i)
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Confirmation", "Fermer cet onglet?", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        alltabptr[i]->close();
        ui->tabWidget->removeTab(i);
        alltabptr.remove(i);
    }
}

void MainWindow::Open()
{
    OpenFile();
}

void MainWindow::OpenFile()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            "Open Document",
            QDir::currentPath(),
            "All files(*.*);; Document files (*.doc *.rtf) ;; PNG files (*.png)");

    if(!filename.isNull())
    {
        qDebug()<<"selected file : "<<filename.toUtf8();
        ReadFile(filename);
    }
}

void MainWindow::ReadFile(QString filename)
{
    QFile file(filename);
    QFileInfo info(file);
    AddTab(info.baseName());
    ui->tabWidget->setCurrentIndex(alltabptr.length()-1);
    newtab* currentTab = alltabptr.at(ui->tabWidget->currentIndex());
    currentTab->ShowFile(&file);
}

void MainWindow::AddTab(QString name)
{
    newtab* newptr = new newtab(this);

    ui->tabWidget->addTab(newptr, name);
    newptr->setAttribute(Qt::WA_DeleteOnClose, true);

    alltabptr.append(newptr);

}

