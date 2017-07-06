#include "repository.h"

EmployeeDAO::EmployeeDAO()
{
    DBConnection::connect();
}

int EmployeeDAO::selectWorkExperience(int id)
{
    QSqlQuery query;
    QString sql = "SELECT DATE('now') - ("
                          "SELECT hire_date FROM employee "
                          "WHERE id = " + QString::number(id) + ")";
    if (!query.exec(sql))
    {
        qDebug() << "Unable to select work exp: "
                        << query.lastError();
        return -1;
    }

    if (query.next()) return query.value(0).toInt();
    else return -1;
}


EmployeeRepository::EmployeeRepository()
{
    DBConnection::connect();
}

Employee EmployeeRepository::select(int id)
{
    QSqlQuery query;
    QString sql = "SELECT firstname, lastname, hire_date, base_rate "
                          "FROM employee "
                          "WHERE id = " + QString::number(id);
    if (!query.exec(sql))
    {
        qDebug() << "Unable to select data: "
                        << query.lastError();
    }

    QSqlRecord rec = query.record();
    if (query.next())
    {
        QString fname = query.value(rec.indexOf("firstname")).toString();
        QString lname = query.value(rec.indexOf("lastname")).toString();
        QDate   hired = query.value(rec.indexOf("hire_date")).toDate();
        double rate = query.value(rec.indexOf("base_rate")).toDouble();

        EmployeeDAO dao;
        int exp = dao.selectWorkExperience(id);

        return Employee(id, fname, lname, hired, rate, exp);
    }

    return Employee();
}
