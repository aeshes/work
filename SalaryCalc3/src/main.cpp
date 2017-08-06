#include <QApplication>

#include "odb-inc.hxx"

#include <iostream>
#include <memory>

#include "db.hxx"
#include "employee.hxx"
#include "employee-odb.hxx"
#include "salary.hxx"
#include "repository.hxx"
#include "mainwindow.h"


using odb::database;
using odb::transaction;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBConnection::connect();

    std::shared_ptr<odb::database> db(new odb::sqlite::database("data.db"));

   employee_repository<Employee> repository(db);
   Dispatcher dispatcher;

   auto e = repository.select(2);
   std::cout << e->name() << std::endl;
   std::cout << e->getWorkExperience() << std::endl;
   std::cout << e->getExtraPayLimit() << std::endl;
   std::cout << e->getExperienceCoeff() << std::endl;
   std::cout << e->salary(dispatcher) << std::endl;

    MainWindow window;
    window.show();

    return a.exec();
}
