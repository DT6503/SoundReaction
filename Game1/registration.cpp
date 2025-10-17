#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QCryptographicHash>
#include <QString>
#include <QSqlQuery>
#include <QFile>
#include <QDir>

Registration::Registration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Registration)
    , currentUserId(-1)
{
    ui->setupUi(this);

    // Создаем поле для ввода пароля

    ui->passwordEdit->setPlaceholderText("Введите пароль");
    ui->passwordEdit->setEchoMode(QLineEdit::Password); // Скрываем вводимые символы
    //passwordEdit->setGeometry(100, 100, 200, 30);   // Позиция и размер (x

    //ui->FIOEdit_2->setPlaceholderText("Введите своё ФИО");
    ui->firstNameEdit->setPlaceholderText("Фамилия");
    ui->lastNameEdit->setPlaceholderText("Имя");
    ui->middleNameEdit->setPlaceholderText("Отчество");

    // Подключение к базе
    connectToDatabase();

    // В конструкторе класса
    this->setStyleSheet("background-color: #f0f9ff;");

    ui->label->setStyleSheet(R"(
    QLabel {
        color: #2c3e50;
        font-size: 13px;
        font-weight: bold;
        background-color: transparent;
    }
)");

    ui->firstNameEdit->setStyleSheet(R"(
    QLineEdit {
        background-color: white;
        border: 2px solid #bbdefb;
        border-radius: 6px;
        font-size: 14px;
        color: #2c3e50;
        selection-background-color: #e3f2fd;
    }
    QLineEdit:focus {
        border-color: #4facfe;
        background-color: #fafdff;
    }
    QLineEdit:hover {
        border-color: #90caf9;
    }
)");

    ui->lastNameEdit->setStyleSheet(R"(
    QLineEdit {
        background-color: white;
        border: 2px solid #bbdefb;
        border-radius: 6px;
        font-size: 14px;
        color: #2c3e50;
        selection-background-color: #e3f2fd;
    }
    QLineEdit:focus {
        border-color: #4facfe;
        background-color: #fafdff;
    }
    QLineEdit:hover {
        border-color: #90caf9;
    }
)");

    ui->middleNameEdit->setStyleSheet(R"(
    QLineEdit {
        background-color: white;
        border: 2px solid #bbdefb;
        border-radius: 6px;
        font-size: 14px;
        color: #2c3e50;
        selection-background-color: #e3f2fd;
    }
    QLineEdit:focus {
        border-color: #4facfe;
        background-color: #fafdff;
    }
    QLineEdit:hover {
        border-color: #90caf9;
    }
)");

    ui->passwordEdit->setStyleSheet(R"(
    QLineEdit {
        background-color: white;
        border: 2px solid #bbdefb;
        border-radius: 6px;
        font-size: 14px;
        color: #2c3e50;
        selection-background-color: #e3f2fd;
    }
    QLineEdit:focus {
        border-color: #4facfe;
        background-color: #fafdff;
    }
    QLineEdit:hover {
        border-color: #90caf9;
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
        margin-top: 10px;
    }
    QPushButton:hover {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #6bbdff, stop:1 #2ad2ff);
    }
    QPushButton:pressed {
        background-color: #1a8fd8;
    }
    QPushButton:disabled {
        background-color: #cfd8dc;
        color: #90a4ae;
    }
)");

}

Registration::~Registration()
{
    delete ui;

}

//new
int Registration::getCurrentUserId() const
{
    return currentUserId;
}

QString Registration::getCurrentUserName() const
{
    return currentUserName;
}

void Registration::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");

    // Путь к Access файлу — замените на свой
    QString dbPath = "D:\\ReactionGame\\Game1\\users1.accdb";

    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=%1").arg(dbPath);
    db.setDatabaseName(dsn);

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка подключения", db.lastError().text());
    } else {
        qDebug() << "База данных успешно подключена.";
    }
}

int Registration::getNextUserId()
{
    QSqlQuery query;
    query.exec("SELECT MAX(id_пользователя) FROM Пользователи");
    if (query.next()) {
        return query.value(0).toInt() + 1;
    }
    return 1;
}

int Registration::getNextUserEntryId()
{
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM Пользователи");
    if (query.next()) {
        return query.value(0).toInt() + 1;
    }
    return 1;
}

int Registration::getDoctorId()
{
    QSqlQuery query;
    query.exec("SELECT TOP 1 id_врача FROM Врачи");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 1;
}

bool Registration::checkUserExists(const QString &firstName, const QString &lastName, const QString &middleName, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT id_пользователя, пароль_хэш FROM Пользователи WHERE фамилия = ? AND имя = ? AND отчество = ?");
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(middleName);

    if (query.exec() && query.next()) {
        QString storedPassword = query.value(1).toString();
        QString hashedPassword = QCryptographicHash::hash(
                                     password.toUtf8(),
                                     QCryptographicHash::Sha256
                                     ).toHex();

        if (storedPassword != hashedPassword) {
            return false; // Пароль не совпадает
        }

        currentUserId = query.value(0).toInt();
        return true; // Пользователь существует и пароль верный
    }

    //Добавила
    qDebug() << "User does not exist - can create new";
    currentUserId = -1; // Сбрасываем ID для нового пользователя
    return true; // Пользователь не существует, можно создавать
}


void Registration::on_pushButton_clicked()
{

    QString firstName = ui->firstNameEdit->text().trimmed();
    QString lastName = ui->lastNameEdit->text().trimmed();
    QString middleName = ui->middleNameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    //QString input = ui->firstNameEdit->text();
    //QString password = ui->passwordEdit->text();
   // QString result = "Hello";
    //QString formattedDateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    if (firstName.isEmpty() || lastName.isEmpty() || middleName.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ввод данных", "Все поля должны быть заполнены!");
        return;
    }

    // Проверяем существование пользователя и пароль
        if (!checkUserExists(firstName, lastName, middleName, password)) {
        QMessageBox::warning(this, "Ошибка", "Пользователь с таким ФИО уже существует, но пароль не совпадает!");
        return;
    }

    // Хеширование пароля
    QString hashedPassword = QCryptographicHash::hash(
                                 password.toUtf8(),
                                 QCryptographicHash::Sha256
                                 ).toHex();

    QString formattedDateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    int doctorId = getDoctorId();

    QSqlQuery query;

    // Если пользователь не существует, создаем нового
    if (currentUserId == -1) {
        currentUserId = getNextUserId();
qDebug() << "Creating new user with ID:" << currentUserId;

        query.prepare("INSERT INTO Пользователи (id_пользователя, фамилия, имя, отчество, пароль_хэш, id_врача) VALUES (?, ?, ?, ?, ?, ?)");

        query.addBindValue(currentUserId);
        query.addBindValue(firstName);
        query.addBindValue(lastName);
        query.addBindValue(middleName);
        query.addBindValue(hashedPassword);
        //query.addBindValue(formattedDateTime);
        query.addBindValue(doctorId);

        if (!query.exec()) {
            QMessageBox::information(this, "Ошибка", "Не удалось сохранить данные: " + query.lastError().text());
            return;
        }

        qDebug() << "New user created successfully! ID:" << currentUserId;
        QMessageBox::information(this, "Успех", "Новый пользователь зарегистрирован!");

    } else {
        // Пользователь существует, добавляем новую запись входа
      /* int nextEntryId = getNextUserEntryId();

      //  query.prepare("INSERT INTO Пользователи (id_пользователя, фамилия, имя, отчество, пароль_хэш, id_врача) VALUES (?, ?, ?, ?, ?, ?)");
        //query.addBindValue(nextEntryId);
        query.addBindValue(currentUserId);
        query.addBindValue(firstName);
        query.addBindValue(lastName);
        query.addBindValue(middleName);
        query.addBindValue(hashedPassword);
      //  query.addBindValue(formattedDateTime);
        query.addBindValue(doctorId);
        */

        QMessageBox::information(this, "Регистрация", "Поздравление с успешной аутентификацией");

    }
 // ВОТ тут
    /*if (!query.exec()) {
        QMessageBox::information(this, "Ошибка", "Не удалось сохранить данные: " + query.lastError().text());
        return;
    }*/

    currentUserName = firstName + " " + lastName + " " + middleName;

    QMessageBox::information(this, "Успех", "Авторизация успешна!");
    ui->firstNameEdit->clear();
    ui->lastNameEdit->clear();
    ui->middleNameEdit->clear();
    ui->passwordEdit->clear();

    this->close();
    // ПРАВИЛЬНЫЙ ВАРИАНТ: создаем объект Play и передаем данные
    Play *playWindow = new Play();
    playWindow->setUserData(currentUserId, currentUserName);
    playWindow->show();
}

void Registration::closeDB(){
    db.close();
    qDebug() << "База данных закрыта по запросу из end";
}




