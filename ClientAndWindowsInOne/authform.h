#ifndef AUTHFORM_H
#define AUTHFORM_H
#include "client.h"
#include <QWidget>
#include "back_func.h"
namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

signals:
    void logged_in();
private slots:
    void on_pushButton_reg_clicked();
    void on_pushButton_ok_clicked();
private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
