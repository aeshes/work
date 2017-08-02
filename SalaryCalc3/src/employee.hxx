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

class abstract_employee;
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


class abstract_employee
{
public:
    virtual ~abstract_employee() {}

    virtual double salary(AbstractDispatcher& dispatcher) = 0;
    virtual double getBaseRate() const = 0;
    virtual double getWorkExperience() const = 0;
    virtual double getManagementCoeff() const = 0;
    virtual double getExtraPayLimit() const = 0;
    virtual double getExperienceCoeff() const = 0;

protected:
    abstract_employee() = default;
};


class employee : public abstract_employee
{
    friend class Dispatcher;
    friend class odb::access;

public:
    enum { type = 1 };

public:
    employee() = default;

    friend std::ostream& operator<<(std::ostream& os, const employee& e);

    double salary(AbstractDispatcher & dispatcher) override;
    double getBaseRate() const override;
    double getWorkExperience() const override;
    double getManagementCoeff() const override;
    double getExtraPayLimit() const override;
    double getExperienceCoeff() const override;
    std::string name() const { return firstname; }

private:
    std::size_t id;
    std::string firstname;
    std::string lastname;
    std::time_t hire_date;
    double base_rate;
};

#pragma db object(employee)
#pragma db member(employee::id) id

std::ostream& operator<<(std::ostream& os, const employee& e);


class manager : public abstract_employee
{
    friend class Dispatcher;
    friend class odb::access;

public:
    enum { type = 2 };

public:
    manager() = default;

    double salary(AbstractDispatcher & dispatcher) override;
    double getBaseRate() const override;
    double getWorkExperience() const override;
    double getManagementCoeff() const override;
    double getExtraPayLimit() const override;
    double getExperienceCoeff() const override;
    std::string name() const { return firstname; }

private:
    std::size_t id;
    std::string firstname;
    std::string lastname;
    std::time_t hire_date;
    double base_rate;
};

#pragma db object(manager)
#pragma db member(manager::id) id

class sales : public abstract_employee
{
    friend class odb::access;

public:
    enum { type = 3 };

public:
    sales() = default;

    double salary(AbstractDispatcher & dispatcher) override;
    double getBaseRate() const override;
    double getWorkExperience() const override;
    double getManagementCoeff() const override;
    double getExtraPayLimit() const override;
    double getExperienceCoeff() const override;
    std::string name() const { return firstname; }

private:
    std::size_t id;
    std::string firstname;
    std::string lastname;
    std::time_t hire_date;
    double base_rate;
};

#pragma db object(sales)
#pragma db member(sales::id) id

#endif // EMPLOYEE_H
