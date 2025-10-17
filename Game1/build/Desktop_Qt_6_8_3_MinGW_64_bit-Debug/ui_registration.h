/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QLabel *label;
    QLineEdit *passwordEdit;
    QLineEdit *FIOEdit_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(400, 300);
        label = new QLabel(Registration);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 10, 141, 41));
        passwordEdit = new QLineEdit(Registration);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(70, 90, 251, 31));
        FIOEdit_2 = new QLineEdit(Registration);
        FIOEdit_2->setObjectName("FIOEdit_2");
        FIOEdit_2->setGeometry(QRect(70, 150, 251, 31));
        pushButton = new QPushButton(Registration);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 210, 121, 41));

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        label->setText(QCoreApplication::translate("Registration", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Registration", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
