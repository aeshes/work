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

    //update(1, 17);

    //f();

    MainWindow window;
    window.show();

    return a.exec();
}
