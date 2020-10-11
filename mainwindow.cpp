#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(enterdb())); //для внесения данных в БД
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterdb(){
//блок внесения текста в БД
}
