#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include "singleton_db.h"


class myfunctions
{
private:
    QSqlDatabase db;
public:
    myfunctions();
    ~myfunctions();

    QString parsing(QString data);

    QString reg(QString login, QString password);

    QString auth(QString login, QString password);
};

#endif // MYFUNCTIONS_H
