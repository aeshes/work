#include <QApplication>

#include <iostream>
#include <memory>

#include "db.h"
#include "employee.h"
#include "salary.h"
#include "repository.h"
#include "mainwindow.h"
#include "employee_record.h"
#include "employee_factory.h"
#include "TestGlobal.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBConnection::connect();

   EmployeeRepository repository;
   Dispatcher dispatcher;

   TestGlobal::testEmployeeHierarchy();

    MainWindow window;
    window.show();

    return a.exec();
}
