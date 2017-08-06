#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <memory>

#include <odb/core.hxx>

#include "salary.hxx"


class AbstractDispatcher;

class AbstractEmployee;
class department;

#pragma db object no_id
class position
{
    friend class odb::access;

public:
    std::size_t employee_id;
    std::auto_ptr<department> department_id;
};

#pragma db object
class department
{
    friend class odb::access;

public:
    #pragma db id
    std::size_t id;

    std::string name;
};

#pragma db object
class AbstractEmployee
{
    friend class odb::access;

public:
    virtual ~AbstractEmployee() {}

    virtual double salary(AbstractDispatcher& dispatcher) = 0;
    virtual double getBaseRate() const;
    virtual int    getWorkExperience() const;
    virtual double getManagementCoeff() const = 0;
    virtual double getExtraPayLimit() const = 0;
    virtual double getExperienceCoeff() const = 0;

    virtual std::string name() const;

protected:
    AbstractEmployee() = default;

protected:
    std::size_t id;
    std::string firstname;
    std::string lastname;
    std::time_t hire_date;
    double base_rate;
};

#pragma db member(AbstractEmployee::id) id auto


class Employee : public AbstractEmployee
{
    friend class Dispatcher;
    friend class odb::access;

public:
    enum { type = 1 };

public:
    Employee() = default;

    virtual int    getWorkExperience() const override;
    virtual double getManagementCoeff() const override;
    virtual double getExtraPayLimit() const override;
    virtual double getExperienceCoeff() const override;

    double salary(AbstractDispatcher & dispatcher) override;
};

#pragma db object(Employee)
#pragma db member(Employee::id) id auto


class Manager : public AbstractEmployee
{
    friend class Dispatcher;
    friend class odb::access;

public:
    enum { type = 2 };

public:
    Manager() = default;

    double salary(AbstractDispatcher & dispatcher) override;
};

#pragma db object(Manager)
#pragma db member(Manager::id) id

class Sales : public AbstractEmployee
{
    friend class odb::access;

public:
    enum { type = 3 };

public:
    Sales() = default;

    double salary(AbstractDispatcher & dispatcher) override;
};

#pragma db object(Sales)
#pragma db member(Sales::id) id

#endif // EMPLOYEE_H
