#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QSoundEffect>
#include <QRandomGenerator>
#include <QDebug>
#include  <QPushButton>
#include <QLabel>

#include <form.h>

namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();

    // добавляем метод для передачи данных
    void setUserData(int id, const QString &name);
    void saveResultToDatabase(qint64 reactionTime);


private:
    Ui::Play *ui;
    Form *sForm;

    QElapsedTimer timer; //высокая точность

    bool waitingForReaction = false;
    qint64 reactionTime;
    QSoundEffect dingSound;
    // QPushButton* startButton;

    QTimer* waitTimer;
    QElapsedTimer reactionTimer;


    QTimer* animationTimer;
    QElapsedTimer animationStart;


    QTimer* waitingTimer;
    QTimer* animatedTimer;

    QLabel result;

    int userId = -1;
    QString userName;

     //void saveResultToDatabase(qint64 reactionTime);

private slots:
    void on_startButton_clicked();
    void playDingAndStartTimer();
    void startGame();
    void on_reactionButton_clicked();
    void updateAnimatedTimer();

};
#endif // MAINWINDOW_H

