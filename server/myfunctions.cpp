#include "myfunctions.h"
#include <QStringList>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMap>

myfunctions::~myfunctions()
{
    db.close();
}


myfunctions::myfunctions()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/acer/forchel/sqlite.db");
    db.open();

}

QString myfunctions::auth(QString login, QString password){
    QString log_from_db, pass_from_db, status_from_db;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM info "
               "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();
    qDebug() << login;
    qDebug() << password;
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");

    while(query.next())
        log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString();
        qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\n";

    QString status = "Wrong username or password";
    //2.
    if (login == log_from_db && password == pass_from_db){
       status = "Welcome";
    }

    return status;
}


QString myfunctions::reg(QString login, QString password){
    QSqlQuery query(db);
    QString status = "";
    QString log_from_db, pass_from_db, email_from_db, status_from_db, name_from_db, surname_from_db;
    query.prepare("SELECT * FROM info "
               "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
        log_from_db = query.value(rec.indexOf("login")).toString();

     if (login == log_from_db){
         status = "You cannot use this username";
     }

     else{

         query.prepare("INSERT INTO info (login, password) "
                           "VALUES (:login, :password)");
         query.bindValue(":password",password);
         query.bindValue(":login",login);
         query.exec();
         status = "Registration success";
     }

    return status;
}

QString myfunctions::parsing(QString data){
    QString status = "Error";
    QStringList list = data.split("&", QString::SplitBehavior::SkipEmptyParts);
    if (list[0] == "authentication"){
         status = auth(list[1], list[2]);
    }
    else if (list[0] == "registration"){
         status = reg(list[1], list[2]);
    }
    return status;

}


