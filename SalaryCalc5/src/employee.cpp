#include "employee.h"

#include <QtSql>
#include <QString>

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
	QSqlQuery q("SELECT DATE('now') - (SELECT hire_date FROM employee " \
		" WHERE id = " + QString::number(id) + ")");
	if (q.next())
	{
		return q.value(0).toInt();
	}
	return 0.0;
}