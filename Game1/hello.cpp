#include "hello.h"
#include "ui_hello.h"

Hello::Hello(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Hello)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #f0f9ff;");

    ui->label->setStyleSheet(R"(
    QLabel {
        color: #1e6fa8;
        font-size: 24px;
        font-weight: bold;
        background-color: transparent;
        padding: 10px;
        qproperty-alignment: 'AlignCenter';
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
        min-width: 120px;
    }
    QPushButton:hover {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #6bbdff, stop:1 #2ad2ff);
    }
    QPushButton:pressed {
        background-color: #1a8fd8;
    }
)");


}

Hello::~Hello()
{
    delete ui;
}

void Hello::on_pushButton_clicked()
{
    reg.show();
    this->close();
}

