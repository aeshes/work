#include "employee.h"

void employee::debug()
{
    qDebug() << "firstname: " << firstname;
    qDebug() << "lastname: " << lastname;
    qDebug() << "hire_date: " << hire_date;
    qDebug() << "base_rate: " << base_rate;
}

employee::employee(int id)
{
    QSqlQuery query;
    QString sql = "SELECT firstname, lastname, hire_date, base_rate "
                          "FROM employee "
                          "WHERE id = " + QString::number(id);
    if (!query.exec(sql))
    {
        qDebug() << "Unable to select data from employee table" << query.lastError();
    }

    QSqlRecord rec = query.record();
    if (query.next())
    {
        firstname = query.value(rec.indexOf("firstname")).toString();
        lastname = query.value(rec.indexOf("lastname")).toString();
        hire_date = query.value(rec.indexOf("hire_date")).toDateTime();
        base_rate = query.value(rec.indexOf("base_rate")).toDouble();
    }
}

int employee::work_experience()
{
    return 0;
}

double employee::salary()
{
    return 0.0;
}
