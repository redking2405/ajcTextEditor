#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow * MainWindow::mainptr = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainptr = this;
    ui->tabWidget->setTabsClosable(true);

    connect(ui->actionOuvrir, SIGNAL(triggered(bool)), this, SLOT(Open()));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(CloseCurrentTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*!
 * \brief MainWindow::GetMainWindow
 * \return
 * Static function to get access to main window in other classes
 */
MainWindow *MainWindow::GetMainWindow()
{
    return mainptr;
}
/*!
 * \brief MainWindow::UpdateTabName
 * \param currentTab
 * Update the tab label if needed called by the tab when text change
 */
void MainWindow::UpdateTabName(newtab* currentTab)
{
    if(currentTab->hasUnsavedChange)
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), currentTab->name+"*");
    else
       ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), currentTab->name);
}
/*!
 * \brief MainWindow::CloseCurrentTab
 * \param i
 * Close the tab, if there is Unsaved changes ask to save the file.
 * Called whne a tab is closing
 */
void MainWindow::CloseCurrentTab(int i)
{
    if(alltabptr[i]->hasUnsavedChange)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Vous avez des modifications non sauvegarder", "Sauvegarder les changements?", QMessageBox::Yes| QMessageBox::No);
        if(reply == QMessageBox::No)
        {
            alltabptr[i]->close();
            ui->tabWidget->removeTab(i);
            alltabptr.remove(i);
        }

        if(reply == QMessageBox::Yes)
        {
            SaveTab(i);
            alltabptr[i]->close();
            ui->tabWidget->removeTab(i);
            alltabptr.remove(i);
        }
    }
    else
    {
        alltabptr[i]->close();
        ui->tabWidget->removeTab(i);
        alltabptr.remove(i);
    }

}
/*!
 * \brief MainWindow::Open
 * Open a file called when ouvrir is pressed
 */
void MainWindow::Open()
{
    OpenFile();
}
/*!
 * \brief MainWindow::OpenFile
 * Open a file if the file exists then read it
 */
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
/*!
 * \brief MainWindow::ReadFile
 * \param filename
 * read the file and add a tab
 */
void MainWindow::ReadFile(QString filename)
{
    QFile file(filename);
    QFileInfo info(file);
    bool fileAlreadyOpened =false;


    int result;
    for(int i=0; i<alltabptr.length(); i++)
    {
        result = QString::compare(info.baseName(), alltabptr.at(i)->name);
        if(result==0 && !fileAlreadyOpened)
        {
            fileAlreadyOpened=true;
        }
    }
    if(!fileAlreadyOpened)
    {
        AddTab(info.baseName());
        ui->tabWidget->setCurrentIndex(alltabptr.length()-1);
        newtab* currentTab = alltabptr.at(ui->tabWidget->currentIndex());
        currentTab->name = info.baseName();
        currentTab->ShowFile(&file);
    }

}
/*!
 * \brief MainWindow::AddTab
 * \param name
 * add a tab to the tab widget
 */
void MainWindow::AddTab(QString name)
{
    newtab* newptr = new newtab(this);

    ui->tabWidget->addTab(newptr, name);
    newptr->setAttribute(Qt::WA_DeleteOnClose, true);

    alltabptr.append(newptr);

}
/*!
 * \brief MainWindow::SaveTab
 * \param i
 * Save the file when the user click yes on the question
 */
void MainWindow::SaveTab(int i)
{
    QString filename = QFileDialog::getSaveFileName(
            this,
            "Save Document",
            QDir::currentPath(),
            "All files(*.*);; Document files (*.doc *.rtf) ;; PNG files (*.png)");
    if(!filename.isNull())
    {
        qDebug()<<"selected file : "<<filename.toUtf8();
        QFile file(filename);
        alltabptr[i]->SaveFile(&file);
    }
}

