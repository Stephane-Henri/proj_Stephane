#ifndef SINGLETON_DB_H
#define SINGLETON_DB_H
//#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


class singleton_db;

class singleton_db_destroyer{
private:
    singleton_db * p_instance;
public:
    ~singleton_db_destroyer();
    void initialize(singleton_db * p);
};


class singleton_db
{
private:
    static singleton_db * p_instance;
    static singleton_db_destroyer destroyer;
    QSqlDatabase db;
protected:
    singleton_db();
    singleton_db(const singleton_db&);
    singleton_db & operator= (singleton_db&);
    ~singleton_db();
    friend class singleton_db_destroyer;
public:
    static singleton_db * getInstance();
    void close_db();
};

#endif // SINGLETON_DB_H
