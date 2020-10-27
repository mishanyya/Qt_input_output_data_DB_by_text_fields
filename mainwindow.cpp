#include "mainwindow.h"
#include "ui_mainwindow.h"






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(inserttodb())); //для внесения данных в БД
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(selectfromdb())); //для получения данных из БД
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
 * //Подключаем базу данных, надо подключать только один раз! Оно должно быть общее для всех кнопок и т.д.!!!
 * и оно должно быть внутри метода MainWindow::***() иначе его не видит программа!!!
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
db.setHostName(DBHOSTNAME);
db.setDatabaseName(DBNAME);
db.setUserName(DBUSERNAME);
db.setPassword(DBPASSWORD);
db.open();
*/


void MainWindow::inserttodb(){

    //начало общего кода для работы с БД

    //подключить драйвер для БД, обычно доступно несколько драйверов, их список содержится в стандартном методе QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");

    //эти функции обычно не требуются:
    //db.setHostName("mishanyya");//имя компьютера
    //db.setUserName("mishanyya");//имя пользователя компьютера
    //db.setPassword("***");//пароль

    db.open();//открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");

    QString name=ui->lineEdit->text();//имя
    QString fone=ui->lineEdit_2->text();//номер телефона
    QString automodel=ui->lineEdit_3->text();//модель авто
    QString price=ui->lineEdit_4->text();//стоимость

    QSqlQuery query( db );//создает объект для запросов SQL

    query.prepare("INSERT INTO basetable (number,name,fone,automodel,price) VALUES (NULL,:name,:fone,:automodel,:price)");

    query.bindValue(":name", name);
    query.bindValue(":fone", fone);
    query.bindValue(":automodel", automodel);
    query.bindValue(":price", price);
    query.exec();
            db.close();//закрыть БД


//конец кода для работы с БД
            //Работает!!!
}

void MainWindow::selectfromdb(){
    //начало общего кода для работы с БД

    //подключить драйвер для БД, обычно доступно несколько драйверов, их список содержится в стандартном методе QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");

    //эти функции обычно не требуются:
    //db.setHostName("mishanyya");//имя компьютера
    //db.setUserName("mishanyya");//имя пользователя компьютера
    //db.setPassword("***");//пароль

    db.open();//открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");

    QSqlQuery query( db );//создает объект для запросов SQL


            query.exec("SELECT * FROM basetable");
            //Вывод значений из БД
            while (query.previous())
                //next() выводит последнее значение таблицы БД
            {
            QString value_0 = query.value(0).toString();//элемент 0 массива вывода
            QString value_1 = query.value(1).toString();//элемент 1 массива вывода
            QString value_2 = query.value(2).toString();//элемент 1 массива вывода
            QString value_3 = query.value(2).toString();//элемент 1 массива вывода
            QString value_4 = query.value(2).toString();//элемент 1 массива вывода

            ui->textEdit->setText(value_0+value_1+value_2+value_3+value_4);
            }
db.close();//закрыть БД
//конец кода для работы с БД
            //Работает!!!
}

