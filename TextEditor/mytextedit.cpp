#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget* parent) : QTextEdit(parent)
{

}
/*!
 * \brief MyTextEdit::CompareContent
 * \param toCompare
 * \return
 * Compare the passed string with original content return true if the same and false otherwise
 */
bool MyTextEdit::CompareContent(QString toCompare)
{
    int result = QString::compare(originalcontent, toCompare);
    if(result==0)
        return true;

    else
        return false;
}
