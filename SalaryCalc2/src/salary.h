#ifndef SALARY_H
#define SALARY_H

#include "employee.h"


class AbstractDispatcher;

class Employee;
class Manager;
class Sales;

class AbstractDispatcher
{
public:
    virtual double dispatch(Employee&) = 0;
    virtual double dispatch(Manager&)  = 0;
    virtual double dispatch(Sales&)    = 0;
};

class Dispatcher : public AbstractDispatcher
{
public:
    double dispatch(Employee& emp);
    double dispatch(Manager& man);
    double dispatch(Sales& sal);
};

#endif // SALARY_H
