#include <QApplication>
#include <QStringList>
#include <QtSql>

#include "db.h"
#include "employee.h"
#include "salary.h"
#include "repository.h"
#include "mainwindow.h"

void f()
{
    QTableView *view = new QTableView;
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(Constants::selectAllEmployees);

    if (model->lastError().isValid())
    {
        qDebug() << model->lastError();
    }

    view->setModel(model);
    view->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DBConnection::connect();
    Dispatcher dispatcher;
    EmployeeRepository repository;

    Employee e = repository.select(1);
    e.debug();

    Manager m(4);
    qDebug() << "Manager salary: "  <<m.salary(dispatcher);

    qDebug() << "base_rate = " << get<double>("base_rate", 1);

    //f();

    MainWindow window;
    window.show();

    return a.exec();
}
