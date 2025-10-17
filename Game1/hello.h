#ifndef HELLO_H
#define HELLO_H

#include <QWidget>
#include <registration.h>

namespace Ui {
class Hello;
}

class Hello : public QWidget
{
    Q_OBJECT

public:
    explicit Hello(QWidget *parent = nullptr);
    ~Hello();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Hello *ui;
    Registration reg;
};

#endif // HELLO_H
