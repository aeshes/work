#include <QCoreApplication>
#include <QStringList>
#include <QtSql>

#include "db.h"
#include "employee.h"
#include "salary.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const DBConnection& conn = DBConnection::instance();

    Dispatcher dispatcher;

    Employee e(5);
    e.debug();

    qDebug() << "Salary: "<< e.salary(dispatcher);

    return a.exec();
}
