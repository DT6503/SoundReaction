#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlDatabase>

#include <play.h>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

    //new
    int getCurrentUserId() const;
    QString getCurrentUserName() const;
   // void saveResultToDatabase(qint64 reactionTime);


public slots:
    void closeDB();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Registration *ui;
    //QLineEdit *passwordEdit; // Добавляем указатель на поле ввода пароля
    QSqlDatabase db;

    //new
    int currentUserId;
    QString currentUserName;

    void connectToDatabase();
    //new
    bool checkUserExists(const QString &firstName, const QString &lastName, const QString &middleName, const QString &password);
    int getNextUserId();
    int getNextUserEntryId();
    int getDoctorId();

    Play play;
};

#endif // REGISTRATION_H
