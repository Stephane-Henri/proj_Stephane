#include "singleton_db.h"

singleton_db * singleton_db::p_instance=0;
singleton_db_destroyer singleton_db::destroyer;

singleton_db_destroyer::~singleton_db_destroyer(){
    qDebug() << "deleted";
    delete p_instance;
}

void singleton_db_destroyer::initialize(singleton_db * p){
    qDebug() << "initialize";
    p_instance = p;
}

singleton_db * singleton_db::getInstance(){
    qDebug() << "get instance";
    if(!p_instance){
        p_instance = new singleton_db();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

singleton_db::singleton_db()
{
    qDebug() << "constructor";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/DELL/Desktop/sqlite.db");

    if (!db.open()){
        qDebug() << "nope";
    }
    else{
        qDebug() << "ok";
    }
}

void singleton_db::close_db(){
    if (db.open()){
        db.close();
        qDebug() << "closed";
    }
    else{
        qDebug() << "already closed";
    }
}

singleton_db::~singleton_db()
{

}
