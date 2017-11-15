#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>
#include <QSharedPointer>

#include "salary.h"
#include "employee_record.h"


class AbstractDispatcher;

class AbstractEmployee
{
public:
	virtual ~AbstractEmployee() = default;

    virtual double salary(AbstractDispatcher& dispatcher) = 0;
    virtual double getBaseRate() const = 0;
    virtual int    getWorkExperience() const = 0;
    virtual double getManagementCoeff() const = 0;
    virtual double getExtraPayLimit() const = 0;
    virtual double getExperienceCoeff() const = 0;
};


class Employee : public AbstractEmployee
{
public:
    Employee() = default;
	Employee(qint64 id) : id(id) {}
	Employee(EmployeeRecord const& rec);

	double getBaseRate() const override;
    int    getWorkExperience() const override;
    double getManagementCoeff() const override;
    double getExtraPayLimit() const override;
    double getExperienceCoeff() const override;

    double salary(AbstractDispatcher & dispatcher) override;

private:
	qint64 id;
};


class Manager : public AbstractEmployee
{
public:
    Manager() = default;
	Manager(EmployeeRecord const& rec) {}

	double getBaseRate() const override;
	int    getWorkExperience() const override;
	double getManagementCoeff() const override;
	double getExtraPayLimit() const override;
	double getExperienceCoeff() const override;

    double salary(AbstractDispatcher & dispatcher) override;
};

class Sales : public AbstractEmployee
{
public:
    Sales() = default;
	Sales(EmployeeRecord const& rec) {}

	double getBaseRate() const override;
	int    getWorkExperience() const override;
	double getManagementCoeff() const override;
	double getExtraPayLimit() const override;
	double getExperienceCoeff() const override;

    double salary(AbstractDispatcher & dispatcher) override;
};

#endif // EMPLOYEE_H
