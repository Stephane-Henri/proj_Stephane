#include "exists_form.h"
#include "ui_exists_form.h"

exists_form::exists_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exists_form)
{
    ui->setupUi(this);
}

exists_form::~exists_form()
{
    delete ui;
}

void exists_form::on_pushButton_clicked()
{
    hide();
}

