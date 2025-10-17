/********************************************************************************
** Form generated from reading UI file 'play.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QLabel *label;
    QLabel *singlescore;
    QPushButton *reactionButton;
    QPushButton *startButton;
    QLCDNumber *scoreDisplay;

    void setupUi(QWidget *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName("Play");
        Play->resize(400, 300);
        label = new QLabel(Play);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 10, 91, 41));
        singlescore = new QLabel(Play);
        singlescore->setObjectName("singlescore");
        singlescore->setGeometry(QRect(130, 70, 111, 31));
        reactionButton = new QPushButton(Play);
        reactionButton->setObjectName("reactionButton");
        reactionButton->setGeometry(QRect(110, 210, 181, 61));
        startButton = new QPushButton(Play);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(130, 150, 141, 41));
        scoreDisplay = new QLCDNumber(Play);
        scoreDisplay->setObjectName("scoreDisplay");
        scoreDisplay->setGeometry(QRect(240, 60, 141, 41));

        retranslateUi(Play);

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QWidget *Play)
    {
        Play->setWindowTitle(QCoreApplication::translate("Play", "Form", nullptr));
        label->setText(QCoreApplication::translate("Play", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#ffffff;\">Game</span></p></body></html>", nullptr));
        singlescore->setText(QCoreApplication::translate("Play", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Single Score:</span></p></body></html>", nullptr));
        reactionButton->setText(QCoreApplication::translate("Play", "\320\240\320\265\320\260\320\272\321\206\320\270\321\217", nullptr));
        startButton->setText(QCoreApplication::translate("Play", "\320\241\321\202\320\260\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
