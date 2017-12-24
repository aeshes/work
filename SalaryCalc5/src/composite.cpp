#include "composite.h"

#include <QtSql>
#include <QString>

#include <cassert>

#include "database.h"


Employee::Employee(unsigned id)
	: id(id)
{

}

double Employee::extraPay() const
{
	static const double EXTRA_PAY_LIMIT = 0.3;

	const double percents = extraPercents();

	if (percents < EXTRA_PAY_LIMIT)
		return baseRate() * percents;
	else
		return baseRate() * EXTRA_PAY_LIMIT;
}

double Employee::percentsPerYear() const
{
	return 0.03;
}

double Employee::extraPercents() const
{
	return percentsPerYear() * workExperience();
}

double Employee::salary() const
{
	return baseRate() + extraPay();
}

double Employee::baseRate() const
{
	return db::selectSingleFieldFromTableByID("employee", "base_rate", id).toDouble();
}

double Employee::workExperience() const
{
	return db::selectExperienceByID(id);
}

Manager::Manager(unsigned id)
	: id(id)
{

}

Manager::~Manager()
{
	for (auto ptr : employees)
	{
		if (ptr) delete ptr;
	}
}

double Manager::salary() const
{
	return baseRate() + extraPay();
}

double Manager::extraPay() const
{
	double base_rate = baseRate();
	assert(base_rate == 50.0);

	static const double EXTRA_PAY_LIMIT = 0.4;
	double percents = 0.05 * workExperience();
	assert(percents == 0.05);

	double result = 0.0;

	if (percents < EXTRA_PAY_LIMIT)
		result = baseRate() * percents;
	else
		result = baseRate() * EXTRA_PAY_LIMIT;

	assert(result == 2.5);

	assert(payForEmployees() == 0.5225);

	result += payForEmployees();

	assert(result == 3.0225);

	return result;
}

double Manager::baseRate() const
{
	return db::selectSingleFieldFromTableByID("employee", "base_rate", id).toDouble();
}

double Manager::workExperience() const
{
	return db::selectExperienceByID(id);
}

double Manager::payForEmployees() const
{
	double result = 0.0;
	for (auto ptr : employees)
	{
		result += ptr->salary() * 0.005;
	}
	return result;
}

void Manager::add(Component *c)
{
	employees.push_back(c);
}

double Sales::salary() const
{
	return 0;
}

void Sales::add(Component *c)
{
	employees.push_back(c);
}