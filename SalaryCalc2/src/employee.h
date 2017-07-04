#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#include "salary.h"


class AbstractDispatcher;

class AbstractEmployee
{
public:
    AbstractEmployee(int id);
    virtual ~AbstractEmployee() = default;

    virtual double salary(AbstractDispatcher& dispatcher) = 0;

protected:
    int          id;
    QString  firstname;
    QString  lastname;
    QDate    hire_date;
    double   base_rate;
    int          work_exp;

    void init(int id);
    void init_work_exp(int id);
};

class Employee : public AbstractEmployee
{
    friend class Dispatcher;
public:
    Employee() = default;
    Employee(int id);

    double salary(AbstractDispatcher& dispatcher) override;
    void debug();

private:
    static constexpr double exp_coeff          = 0.03;
    static constexpr double extra_pay_limit = 0.3;
};

class Manager : public AbstractEmployee
{
public:
    Manager() = default;
    Manager(int id);

    double salary(AbstractDispatcher& dispatcher) override;

private:
    static constexpr double exp_coeff          = 0.03;
    static constexpr double extra_pay_limit = 0.4;
    static constexpr double emp_coeff         = 0.005;
};

class Sales : public AbstractEmployee
{
public:
    Sales() = default;
    Sales(int id);

    double salary(AbstractDispatcher& dispatcher) override;
};

#endif // EMPLOYEE_H
