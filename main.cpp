#include "mainwindow.h"

//#include "QSqlDatabase"
//#include "QtSql/QSqlDatabase"
//#include "QSqlQuery"
//#include "QtSql"
//#include "QTableView"

#include "QApplication"

int main(int argc, char *argv[])
{
QApplication a(argc, argv);

MainWindow w;
w.show();
return a.exec();
}
