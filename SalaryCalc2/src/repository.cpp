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

    if (query.next())
        return query.value(0).toInt();
    else return -1;
}


EmployeeRepository::EmployeeRepository()
{
    DBConnection::connect();
}

Employee EmployeeRepository::select(int id)
{
    EmployeeDAO dao;

    QString fname = get<QString>("firstname", id);
    QString lname = get<QString>("lastname", id);
    QDate   hired = get<QDate>  ("hire_date", id);
    double  rate  = get<double> ("base_rate", id);
    int     exp   = dao.selectWorkExperience(id);

    return Employee(id, fname, lname, hired, rate, exp);
}
