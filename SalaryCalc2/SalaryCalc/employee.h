#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>


class employee
{
public:
    employee()               = default;
    employee(int id);
    virtual ~employee() = default;

    virtual int work_experience();
    virtual double salary();

    void debug();

protected:
    int               id;
    QString       firstname;
    QString       lastname;
    QDateTime hire_date;
    double        base_rate;
};

#endif // EMPLOYEE_H
