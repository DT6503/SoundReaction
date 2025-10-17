/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(400, 300);
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 120, 221, 61));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 210, 131, 41));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 40, 181, 31));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 210, 131, 41));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\">\320\226\320\265\320\273\320\260\320\265\321\210\321\214 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214?</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\320\237\320\276\320\267\320\264\321\200\320\260\320\262\320\273\321\217\320\265\320\274!</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
