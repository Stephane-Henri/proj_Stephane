#include "form_task.h"
#include "ui_form_task.h"

Form_task::Form_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_task)
{
    ui->setupUi(this);

}


Form_task::~Form_task()
{
    delete ui;
}


void Form_task::on_pushButton_ok_clicked()
{

}


