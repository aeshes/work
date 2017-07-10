#include "employee.h"

AbstractEmployee::AbstractEmployee(int id)
    : id(id)
{
    init(id);
    init_work_exp(id);
}

AbstractEmployee::AbstractEmployee
(
        int     id,
        QString fname,
        QString lname,
        QDate   hired,
        double  rate,
        int     exp
)
    : id(id), firstname(fname), lastname(lname),
      hire_date(hired), base_rate(rate), work_exp(exp)
{}

void AbstractEmployee::init(int id)
{
    QSqlQuery query;
    QString sql = "SELECT firstname, lastname, hire_date, base_rate "
                  "FROM employee "
                  "WHERE id = " + QString::number(id);
    if (!query.exec(sql))
    {
        qDebug() << "Unable to select data from employee table"
                 << query.lastError();
    }

    this->id = id;
    QSqlRecord rec = query.record();
    if (query.next())
    {
        firstname = query.value(rec.indexOf("firstname")).toString();
        lastname  = query.value(rec.indexOf("lastname")).toString();
        hire_date = query.value(rec.indexOf("hire_date")).toDate();
        base_rate = query.value(rec.indexOf("base_rate")).toDouble();
    }
}

void AbstractEmployee::init_work_exp(int id)
{
    QSqlQuery query;
    QString sql = "SELECT DATE('now') - (SELECT hire_date FROM employee WHERE id = "
                + QString::number(id) + ")";
    query.exec(sql);
    if (query.next())
    {
        work_exp = query.value(0).toInt();
    }
}

void Employee::debug()
{
    qDebug() << "firstname: " << firstname;
    qDebug() << "lastname: "  << lastname;
    qDebug() << "hire_date: " << hire_date;
    qDebug() << "base_rate: " << base_rate;
    qDebug() << "exp: "       << work_exp;
}

Employee::Employee(int id)
    : AbstractEmployee(id)
{}

double Employee::salary(AbstractDispatcher &dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Manager::salary(AbstractDispatcher &dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Sales::salary(AbstractDispatcher &dispatcher)
{
    return dispatcher.dispatch(*this);
}
