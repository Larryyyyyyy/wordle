/********************************************************************************
** Form generated from reading UI file 'gameplay.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPLAY_H
#define UI_GAMEPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameplay
{
public:

    void setupUi(QWidget *gameplay)
    {
        if (gameplay->objectName().isEmpty())
            gameplay->setObjectName("gameplay");
        gameplay->resize(400, 300);

        retranslateUi(gameplay);

        QMetaObject::connectSlotsByName(gameplay);
    } // setupUi

    void retranslateUi(QWidget *gameplay)
    {
        gameplay->setWindowTitle(QCoreApplication::translate("gameplay", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameplay: public Ui_gameplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPLAY_H
