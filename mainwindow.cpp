#include "mainwindow.h"
#include "ui_mainwindow.h"


//#include <QTableView>//добавлено для вывода БД в таблице
//#include "QStandardItemModel"//добавлено для вывода БД в таблице
//#include "QStandardItem"//добавлено для вывода БД в таблице

/*для исправления ошибки QSqlDatabasePrivate::addDatabase: duplicate connection name 'qt_sql_default_connection', old connection removed
подключать драйвер для БД (обычно доступно несколько драйверов, их список содержится в стандартном методе QSqlDatabase::drivers();)
следует в глобальной переменной static (видно везде в одном файле)  или extern (видно везде во всех файлах) */
static QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");// db - это статическая глобальная переменная, которую можно использовать только в этом файле

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(inserttodb())); //для внесения данных в БД
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(selectfromdb())); //для получения данных из БД
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(gettingexpierence())); //для получения опыта работы с БД
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::inserttodb(){
    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    //открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    db.open();

    QString name=ui->lineEdit->text();//имя
    QString fone=ui->lineEdit_2->text();//номер телефона
    QString automodel=ui->lineEdit_3->text();//модель авто
    QString price=ui->lineEdit_4->text();//стоимость

    //создает объект для запросов SQL
    QSqlQuery query( db );

    query.prepare("INSERT INTO basetable (number,name,fone,automodel,price) VALUES (NULL,:name,:fone,:automodel,:price)");

    query.bindValue(":name", name);
    query.bindValue(":fone", fone);
    query.bindValue(":automodel", automodel);
    query.bindValue(":price", price);
    query.exec();

    //закрыть БД
    db.close();
}

void MainWindow::selectfromdb(){
    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    //открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    db.open();

    //создает объект для запросов SQL
    QSqlQuery query( db );

    query.exec("SELECT * FROM basetable");

    //Вывод всех значений из БД
    while (query.next())
    {
    QString value_0 = query.value(0).toString();//value(0)-элемент 0 массива вывода
    QString value_1 = query.value(1).toString();//value(1)-элемент 1 массива вывода
    QString value_2 = query.value(2).toString();//value(2)-элемент 2 массива вывода
    QString value_3 = query.value(3).toString();//value(3)-элемент 3 массива вывода
    QString value_4 = query.value(4).toString();//value(4)-элемент 4 массива вывода

    ui->textEdit->insertPlainText(value_0+" "+value_1+" "+value_2+" "+value_3+" "+value_4+"\n");//Вывод всех строк из таблицы БД
    }

    //закрыть БД
    db.close();
}


void MainWindow::gettingexpierence(){
    //подключить БД по ее адресу на компьютере
    db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    //открывает базу данных, указанную в db.setDatabaseName("/home/mishanyya/fordbwork/examplebdfordbwork");
    db.open();

    //создает объект для запросов SQL
    QSqlQuery query( db );

    query.exec("SELECT * FROM basetable");

    //вывод ВСЕХ значений согласно условию
    while (query.next())
    {
    QString value_0 = query.value(0).toString();//value(0)-элемент 0 массива вывода
    QString value_1 = query.value(1).toString();//value(1)-элемент 1 массива вывода
    QString value_2 = query.value(2).toString();//value(2)-элемент 2 массива вывода
    QString value_3 = query.value(3).toString();//value(3)-элемент 3 массива вывода
    QString value_4 = query.value(4).toString();//value(4)-элемент 4 массива вывода

    ui->textEdit_2->append(value_0+" "+value_1+" "+value_2+" "+value_3+" "+value_4+"\n");// Выводит все строки из таблицы БД с небольшим интервалом между ними
    //ui->textEdit_2->setText(value_0+" "+value_1+" "+value_2+" "+value_3+" "+value_4+"\n");// Выводит только последнюю строку из таблицы БД
    //ui->textEdit_2->insertPlainText(value_0+" "+value_1+" "+value_2+" "+value_3+" "+value_4+"\n");//Выводит все строки из таблицы БД
    }

     //проверка работы запроса к БД
     if (query.isActive()){
     ui->label_2->setText("Запрос сработал!");
     }
     else {
     ui->label_2->setText(query.lastError().text());
     }
    //закрыть БД
    db.close();
}
