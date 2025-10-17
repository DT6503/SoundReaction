#include "play.h"
#include "ui_play.h"

#include <QPropertyAnimation>
#include <QRect>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>



Play::Play(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Play)
{
    ui->setupUi(this);
    setWindowTitle("⚡ Reaction Game — Проверь свою реакцию!");
    sForm = new Form();

    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sForm, &Form::playWindow, this, &Play::show);



    this->setStyleSheet("background-color: #f0f8ff;");

    ui->label->setStyleSheet(R"(
    QLabel {
        color: #2c3e50;
        font-size: 24px;
        font-weight: bold;
        background-color: transparent;

    }
)");

    ui->startButton->setStyleSheet(R"(
    QPushButton {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #4facfe, stop:1 #00c6fb);
        color: white;
        border: none;
        font-size: 16px;
        font-weight: bold;
        border-radius: 10px;
        min-width: 130px;
        min-height: 40px;

        qproperty-alignment: 'AlignCenter';
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

    ui->reactionButton->setStyleSheet(R"(
    QPushButton {
        background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                          stop:0 #4facfe, stop:1 #00c6fb);
        color: white;
        border: none;
        font-size: 16px;
        font-weight: bold;
        border-radius: 10px;
        min-width: 150px;
        min-height: 50px;

        qproperty-alignment: 'AlignCenter';
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

    ui->scoreDisplay->setStyleSheet(R"(
    QLCDNumber {
        background-color: #e3f2fd;
        color: #1e6fa8;
        border: 3px solid #90caf9;
        border-radius: 10px;
        min-width: 140px;
        min-height: 20px;
    }
)");

    /*ui->singlescore->setStyleSheet(R"(
    QLabel {
        color: #1e6fa8;
        background-color: #e3f2fd;
        border: 2px solid #90caf9;
        border-radius: 8px;
        font: bold 16px "Segoe UI";
        text-align: center;
        min-width: 100px;
        min-height: 20px;
        qproperty-alignment: 'AlignCenter';
    }
)");*/


    // Шрифт
    QFont font("Consolas", 16, QFont::Bold);
   // ui->singlescore->setFont(font);
    ui->scoreDisplay->setFont(font);

    // Анимация появления кнопки
    QPropertyAnimation *anim = new QPropertyAnimation(ui->startButton, "geometry");
    anim->setDuration(500);
    anim->setStartValue(QRect(0, 0, 0, 0));
    anim->setEndValue(ui->startButton->geometry());
    anim->start(QAbstractAnimation::DeleteWhenStopped);


    //logic of work
    waitTimer = new QTimer(this);
    waitTimer->setSingleShot(true);//одноразовый режим (single-shot mode).
    //Это значит, что таймер сработает только один раз после запуска, а затем автоматически остановится.

    connect (waitTimer, &QTimer::timeout, this, &Play::playDingAndStartTimer);

    dingSound.setSource(QUrl::fromLocalFile("D:/ReactionGame/ReactionGame/ding.wav"));  // добавлю позже в ресурсы
    dingSound.setVolume(0.8);
    waitingForReaction = false;


    ui->reactionButton->setEnabled(false);
    connect(ui->reactionButton, &QPushButton::clicked, this, &Play::on_reactionButton_clicked);


    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Play::updateAnimatedTimer);


    //бд
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("reaction_game.db");

    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS results ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "username TEXT, "
                   "reaction_time INTEGER, "
                   "timestamp TEXT)");
    }*/



}

Play::~Play()
{
    delete ui;
}

void Play::setUserData(int id, const QString &name)
{
    userId = id;
    userName = name;
    qDebug() << "Пользователь установлен:" << userId << userName;
}


void Play::on_startButton_clicked()
{
    //логика
    if (!waitingForReaction) {
        startGame();
    } else {
        qint64 ms = reactionTimer.elapsed();
        result.setText(QString("Ваша реакция: %1 мс").arg(ms));
        ui->startButton->setEnabled(true);
        waitingForReaction = false;
    }

    qDebug()<<"Игра началась!"; //в консоли
}

void Play::startGame()
{
    ui->startButton->setEnabled(false);
   // ui->singlescore->setText("Ждите...");
    ui->reactionButton->setEnabled(false); //the buttton is not active until dzing

    int delay = QRandomGenerator::global()->bounded(1500,6000);// 2-5 сек

    waitTimer->start(delay);
    waitingForReaction=false;

}
void Play::playDingAndStartTimer() {
    dingSound.play();
    reactionTimer.start();
    animationStart.start(); // замер времени анимации
    animationTimer->start(50); // каждые 50 мс обновление текста


   // ui->singlescore->setText("Нажмите сейчас!");
    ui->reactionButton->setEnabled(true); //is active
    waitingForReaction = true;



}



void Play::on_reactionButton_clicked()
{
    if (!waitingForReaction) return;
    animationTimer->stop();
    qint64 ms = reactionTimer.elapsed();
    double seconds = ms / 1000;//в сек

  //  ui->singlescore->setText(QString("Ваша реакция: %1 мс").arg(ms));
    ui->scoreDisplay->display(QString::number(seconds, 'f', 3));//3 num-s after point

    ui->reactionButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    waitingForReaction = false;

    // Здесь позже доб-ю запись в бд
    // Сохраняем результат в базу данных
    saveResultToDatabase(ms);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Результат");
    msgBox.setText(QString("Ваша реакция: %1 мс").arg(ms));
    msgBox.setStyleSheet("QMessageBox { background-color: #ffffe0; }"
                         "QPushButton { background-color: #f0e68c; padding: 5px 10px; }");
    msgBox.exec();

    sForm->show();
    this->close();

}

void Play::saveResultToDatabase(qint64 reactionMs)
{
    /* if (userId == -1) return;

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "База данных не открыта";
        return;
    }


    QString formattedDateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    // Получаем следующий ID результата
    QSqlQuery maxQuery;
    maxQuery.exec("SELECT MAX(id_результата) FROM Результаты");
    int maxResultId = 0;
    if (maxQuery.next()) {
        maxResultId = maxQuery.value(0).toInt();
    }
    int newResultId = maxResultId + 1;

    // Сохраняем результат в таблицу Результаты
    QSqlQuery query;
    query.prepare("INSERT INTO Результаты (id_пользователя, время_прохождения, результат) VALUES (?, ?, ?)");
    //query.addBindValue(newResultId);
    query.addBindValue(userId);
    query.addBindValue(formattedDateTime);
    query.addBindValue(reactionTimer);

    if (!query.exec()) {
        qDebug() << "Ошибка сохранения результата:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось сохранить результат: " + query.lastError().text());
    } else {
        qDebug() << "Результат успешно сохранен. ID:" << newResultId << "Пользователь:" << userId << "Результат:" << reactionTime << "мс";
    }*/



    if (userId == -1) {
        qDebug() << "Play::saveResultToDatabase: userId == -1 — ничего не сохраняем";
        return;
    }

    // Если при подключении ты использовал имя соединения, подставь его сюда:
    QSqlDatabase db = QSqlDatabase::database("access_conn"); // <- если у тебя нет именованного соединения, замените на QSqlDatabase::database()
    if (!db.isValid()) {
        db = QSqlDatabase::database(); // fallback на default
    }

    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Не удалось открыть DB:" << db.lastError().text();
            QMessageBox::critical(nullptr, "Ошибка DB", "Не удалось открыть базу данных: " + db.lastError().text());
            return;
        }
    }

    // Быстрая проверка: доступна ли таблица Результаты?
    {
        QSqlQuery test(db);
        if (!test.exec("SELECT TOP 1 * FROM [Результаты]")) {
            // В Access синтаксис SELECT TOP 1 корректен; если падает — посмотрим ошибку
            qDebug() << "Проверка таблицы 'Результаты' не удалась:" << test.lastError().text();
            QMessageBox::warning(nullptr, "Ошибка DB",
                                 "Не найдена таблица [Результаты] или ошибка доступа: " + test.lastError().text());
            return;
        }
    }

    // Подготовим INSERT (не вставляем id_результата — это счётчик)
    QSqlQuery query(db);
    const QString sql = "INSERT INTO [Результаты] ([id_пользователя], [время_прохождения], [результат]) VALUES (?, ?, ?)";
    if (!query.prepare(sql)) {
        qDebug() << "Prepare failed:" << query.lastError().text() << " SQL:" << sql;
        QMessageBox::critical(nullptr, "Ошибка SQL", "Ошибка подготовки запроса: " + query.lastError().text());
        return;
    }

    // Порядок bind'ов должен точно соответствовать плейсхолдерам
    QVariant vUserId = QVariant(userId);
    QString timeStr = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    QVariant vTime = QVariant(timeStr);
    QVariant vResult = QVariant(static_cast<int>(reactionMs)); // Access ожидает числовой тип для 'результат'

    query.addBindValue(vUserId);
    query.addBindValue(vTime);
    query.addBindValue(vResult);

    if (!query.exec()) {
        qDebug() << "Exec failed:" << query.lastError().text();
        qDebug() << "lastQuery():" << query.lastQuery();
        QMessageBox::critical(nullptr, "Ошибка записи",
                              "Не удалось сохранить результат: " + query.lastError().text());
        return;
    }

    qDebug() << "Результат успешно сохранён. userId:" << userId
             << " result(ms):" << reactionMs
             << " time:" << timeStr;
}


void Play::updateAnimatedTimer() {
    qint64 elapsed = reactionTimer.elapsed();
    double seconds = elapsed / 1000.0;
    ui->scoreDisplay->display(QString::number(seconds, 'f', 3));//анимация
}

