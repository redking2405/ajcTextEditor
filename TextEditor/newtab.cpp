#include "newtab.h"
#include "ui_newtab.h"

newtab::newtab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newtab)
{
    ui->setupUi(this);
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(Update()));
}

newtab::~newtab()
{
    delete ui;
}

void newtab::ShowFile(QFile* file)
{

    QString line;
    ui->textEdit->clear();
    if (file->open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream stream(file);
        while(!stream.atEnd())
        {
            ui->textEdit->setText(stream.readAll());
        }
    }
    file->close();
}

void newtab::Update()
{
    qDebug()<<"le texte a été modifié\n";

}
