#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QWidget>
#include <QString>

class MyTextEdit : public QTextEdit
{
public:
    MyTextEdit(QWidget* parent = nullptr);
    QString originalcontent;
    bool CompareContent(QString toCompare);

};

#endif // MYTEXTEDIT_H
