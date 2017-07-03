#include <QCoreApplication>
#include <QStringList>
#include <QtSql>

#include <iostream>

#include "db.h"
#include "employee.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const DBConnection& conn = DBConnection::instance();

    QStringList lst = conn.get().tables();
    foreach(QString str, lst)
    {
        qDebug() << str;
    }

    employee e(2);
    e.debug();

    return a.exec();
}
