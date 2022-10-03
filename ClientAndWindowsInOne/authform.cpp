#include "authform.h"
#include "ui_authform.h"
#include "back_func.h"
AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->pushButton_reg->setVisible(true);
    ui->pushButton_ok->setVisible(true);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_pushButton_reg_clicked()
{
    ui->pushButton_reg->setVisible(false);
    ui->pushButton_ok->setVisible(true);
}

void AuthForm::on_pushButton_ok_clicked()
{
    QString log = ui->lineEdit_1log->text();
    QString pass = ui->lineEdit_2pass->text();
    if(!ui->pushButton_reg->isVisible()){
        reg(log, pass);
        qDebug() << "reg";
        ui->pushButton_reg->setVisible(true);
        ui->pushButton_ok->setVisible(true);
    }else{
        auth(log, pass);
        qDebug() << "auth";
    }
}

