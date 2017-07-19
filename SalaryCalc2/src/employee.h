#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QList>

#include "salary.h"


template <typename ReturnType>
ReturnType get(const QString &field, int id)
{
    QSqlQuery query;
    QString sql = "SELECT " + field + " FROM employee WHERE id = :id";

    query.prepare(sql);
    query.bindValue(":id", QVariant(id));
    query.exec();
    query.next();

    return qvariant_cast<ReturnType>(query.value(0));
}

class AbstractDispatcher;

class AbstractEmployee
{
public:
    virtual ~AbstractEmployee() = default;

    virtual double salary(AbstractDispatcher& dispatcher) = 0;

protected:
    int      id;
    QString  firstname;
    QString  lastname;
    QDate    hire_date;
    double   base_rate;
    int      work_exp;

    AbstractEmployee() = default;
    AbstractEmployee(int id);
    AbstractEmployee(
            int          id,
            QString fname,
            QString lname,
            QDate   hired,
            double  rate,
            int         exp);

    void init(int id);
    void init_work_exp(int id);
};

class Employee : public AbstractEmployee
{
    friend class Dispatcher;
public:
    Employee() = default;
    Employee(int id);
    Employee(int a, QString b, QString c, QDate d, double e, int f)
        : AbstractEmployee(a, b, c, d, e, f) {}

    double salary(AbstractDispatcher & dispatcher) override;
    void debug();

private:
    static constexpr double exp_coeff       = 0.03;
    static constexpr double extra_pay_limit = 0.3;
};

class LazyEmployeeList
{
    QList<Employee> lazy;

public:
    LazyEmployeeList(int id);
    QList<Employee>::iterator begin();
    QList<Employee>::iterator end();

private:
    bool loaded;
    int _id;
    void load_from_db(int id);
};

class Manager : public AbstractEmployee
{
    friend class Dispatcher;
    LazyEmployeeList employees;

public:
    Manager() = default;
    Manager(int id);

    double salary(AbstractDispatcher & dispatcher) override;

private:
    static constexpr double exp_coeff       = 0.03;
    static constexpr double extra_pay_limit = 0.4;
    static constexpr double emp_coeff       = 0.005;
};

class Sales : public AbstractEmployee
{
public:
    Sales() = default;
    Sales(int id);

    double salary(AbstractDispatcher & dispatcher) override;
};

#endif // EMPLOYEE_H
