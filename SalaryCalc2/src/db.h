#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QString>
#include <QDebug>


class DBConnection
{
    static QSqlDatabase db;

public:
    static const DBConnection& connect()
    {
        static DBConnection inst;
        return inst;
    }

    static QSqlDatabase& get()
    {
        return db;
    }

private:
    DBConnection();
    DBConnection(const DBConnection&);
    DBConnection& operator=(const DBConnection&);
};


#endif // DB_H
