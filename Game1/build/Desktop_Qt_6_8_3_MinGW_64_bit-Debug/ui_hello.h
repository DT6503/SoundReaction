/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hello
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Hello)
    {
        if (Hello->objectName().isEmpty())
            Hello->setObjectName("Hello");
        Hello->resize(400, 300);
        label = new QLabel(Hello);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 311, 71));
        pushButton = new QPushButton(Hello);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 180, 151, 41));

        retranslateUi(Hello);

        QMetaObject::connectSlotsByName(Hello);
    } // setupUi

    void retranslateUi(QWidget *Hello)
    {
        Hello->setWindowTitle(QCoreApplication::translate("Hello", "Form", nullptr));
        label->setText(QCoreApplication::translate("Hello", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\237\321\200\320\270\320\262\320\265\321\202!</span></p><p align=\"center\"><span style=\" font-size:12pt;\">\320\240\320\260\320\264\321\213 \321\202\320\265\320\261\321\217 \320\277\321\200\320\270\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\267\320\264\320\265\321\201\321\214</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Hello", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hello: public Ui_Hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
