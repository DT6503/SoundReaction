#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    // В конструкторе класса
    this->setStyleSheet("background-color: #f0f9ff;");

    ui->label->setStyleSheet(R"(
    QLabel {
        color: #1e6fa8;
        font-size: 24px;
        font-weight: bold;
        background-color: transparent;
    }
)");

    ui->label_2->setStyleSheet(R"(
    QLabel {
        color: #2c3e50;
        font-size: 14px;
        background-color: transparent;
    }
)");

    ui->pushButton->setStyleSheet(R"(
    QPushButton {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #4facfe, stop:1 #00c6fb);
        color: white;
        border: none;
        font-size: 14px;
        font-weight: bold;
        border-radius: 8px;
        min-width: 100px;
    }
    QPushButton:hover {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #6bbdff, stop:1 #2ad2ff);
    }
    QPushButton:pressed {
        background-color: #1a8fd8;
    }
)");

    ui->pushButton_2->setStyleSheet(R"(
    QPushButton {
        background-color: #e3f2fd;
        color: #1e6fa8;
        border: 2px solid #90caf9;

        font-size: 14px;
        font-weight: bold;
        border-radius: 8px;
        min-width: 100px;
    }
    QPushButton:hover {
        background-color: #bbdefb;
        border-color: #64b5f6;
    }
    QPushButton:pressed {
        background-color: #90caf9;
    }
)");
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit playWindow(); // И вызываем сигнал на открытие главного окна

}


void Form::on_pushButton_2_clicked()
{
    this->close();
}

