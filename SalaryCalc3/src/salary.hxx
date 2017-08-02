#ifndef SALARY_H
#define SALARY_H

#include "employee.hxx"


class AbstractDispatcher;

class employee;
class manager;
class sales;

class AbstractDispatcher
{
public:
    virtual double dispatch(employee&) = 0;
    virtual double dispatch(manager&)  = 0;
    virtual double dispatch(sales&)    = 0;
};

class Dispatcher : public AbstractDispatcher
{
public:
    double dispatch(employee& emp);
    double dispatch(manager& man);
    double dispatch(sales& sal);
};

#endif // SALARY_H
