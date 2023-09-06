#include "newtab.h"
#include "ui_newtab.h"
#include "mainwindow.h"
/*!
 * \brief newtab::newtab
 * \param parent
 */
newtab::newtab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newtab)
{
    ui->setupUi(this);

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(Update()));
    //connect(ui->textEdit->document(), SIGNAL(cursorPositionChanged(QTextCursor)), this, SLOT(UpdateCursor()));
    connect(ui->textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(UpdateCursor()));
    //connect(ui->pushButtonSearch, SIGNAL(clicked(bool)), this, SLOT(FindText()));
    //connect (ui->pushButtonReplace, SIGNAL(clicked(bool)), this, SLOT(ReplaceText()));
    fileOpened=false;
    hasUnsavedChange=false;
}

newtab::~newtab()
{
    delete ui;
}
/*!
 * \brief newtab::FindText
 */
/*void newtab::FindText()
{
    QString toFind = ui->inputText->text();
    QString find;
    if(!toFind.isNull())
    {

    }
}*/
/*!
 * \brief newtab::UpdateCursor
 * Slot to be called when the cursor move and set the coordinates in a label
 */
void newtab::UpdateCursor()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    //qDebug()<<"position cursor : "<<cursor.x();
    QString string;
    QTextStream (&string)<<"X : "<<cursor.blockNumber()<<" Y : "<<cursor.positionInBlock();
    ui->textCursor->setText(string);
}
/*!
 * \brief newtab::ShowFile
 * \param file
 * Display the file in the text edit
 */
void newtab::ShowFile(QFile* file)
{


    ui->textEdit->clear();
    if (file->open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream stream(file);
        while(!stream.atEnd())
        {
            ui->textEdit->originalcontent = stream.readAll();
            ui->textEdit->setText(ui->textEdit->originalcontent);

        }
    }
    fileOpened=true;
    qDebug()<<ui->textEdit->originalcontent;
    file->close();

}
/*!
 * \brief newtab::SaveFile
 * \param file
 * Save the file in an existing or new file
 */
void newtab::SaveFile(QFile *file)
{

    if (file->open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream out(file);
        out<<ui->textEdit->toPlainText();
    }
    fileOpened=true;
    file->close();
}
/*!
 * \brief newtab::Update
 * Check if the file has been modified and call a function to update the tab label if needed
 */
void newtab::Update()
{
    QString toC = ui->textEdit->toPlainText();
    if(fileOpened)
    {
        if(!ui->textEdit->CompareContent(toC) && !hasUnsavedChange)
        {
            hasUnsavedChange=true;
            MainWindow::GetMainWindow()->UpdateTabName(this);

        }

        else if(ui->textEdit->CompareContent(toC))
        {
            hasUnsavedChange=false;
            MainWindow::GetMainWindow()->UpdateTabName(this);

        }
    }

}
