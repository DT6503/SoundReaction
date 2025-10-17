/********************************************************************************
** Form generated from reading UI file 'end.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END_H
#define UI_END_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_end
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *end)
    {
        if (end->objectName().isEmpty())
            end->setObjectName("end");
        end->resize(400, 300);
        label = new QLabel(end);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 30, 181, 31));
        label_2 = new QLabel(end);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 110, 221, 61));
        pushButton = new QPushButton(end);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 200, 131, 41));
        pushButton_2 = new QPushButton(end);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 200, 131, 41));

        retranslateUi(end);

        QMetaObject::connectSlotsByName(end);
    } // setupUi

    void retranslateUi(QWidget *end)
    {
        end->setWindowTitle(QCoreApplication::translate("end", "Form", nullptr));
        label->setText(QCoreApplication::translate("end", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\320\237\320\276\320\267\320\264\321\200\320\260\320\262\320\273\321\217\320\265\320\274!</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("end", "<html><head/><body><p align=\"center\">\320\226\320\265\320\273\320\260\320\265\321\210\321\214 \320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214?</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("end", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("end", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class end: public Ui_end {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END_H
