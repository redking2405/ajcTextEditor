/********************************************************************************
** Form generated from reading UI file 'newtab.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTAB_H
#define UI_NEWTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newtab
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *newtab)
    {
        if (newtab->objectName().isEmpty())
            newtab->setObjectName(QString::fromUtf8("newtab"));
        newtab->resize(16, 16);
        horizontalLayoutWidget = new QWidget(newtab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 258, 194));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);


        retranslateUi(newtab);

        QMetaObject::connectSlotsByName(newtab);
    } // setupUi

    void retranslateUi(QWidget *newtab)
    {
        newtab->setWindowTitle(QCoreApplication::translate("newtab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newtab: public Ui_newtab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTAB_H
