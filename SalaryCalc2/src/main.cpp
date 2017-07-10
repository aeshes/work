#include <QCoreApplication>
#include <QStringList>
#include <QtSql>

#include <iostream>

#include "db.h"
#include "employee.h"
#include "salary.h"
#include "repository.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBConnection::connect();
    Dispatcher dispatcher;
    EmployeeRepository repository;

    Employee e = repository.select(1);
    e.debug();

    update(1, 17);

    return a.exec();
}
