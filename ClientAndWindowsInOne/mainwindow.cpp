#include "mainwindow.h"
#include "back_func.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_f = new AuthForm;
    auth_f->show();
    connect(client::getInstance(), &client::welcome, this, &MainWindow::success);
}


void MainWindow::success()
{
    auth_f->hide();
    this->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}


