#include <QCoreApplication>
#include <QStringList>
#include <QtSql>

#include "db.h"
#include "employee.h"
#include "salary.h"
#include "repository.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBConnection::connect();
    EmployeeDAO dao;

    EmployeeRepository repository;

    Dispatcher dispatcher;

    Employee e = repository.select(5);
    e.debug();

    qDebug() << "Salary: "<< e.salary(dispatcher);

    qDebug() << dao.selectWorkExperience(5);

    return a.exec();
}
