#include "back_func.h"
#include <QDebug>

void auth(QString login, QString password){
    QString res = "authentication&" + login + "&" + password + "&";
    client::getInstance()->sendToServer(res);
}

void reg(QString login, QString password){
    QString res = "registration&" + login + "&" + password + "&";
    client::getInstance()->sendToServer(res);

}
