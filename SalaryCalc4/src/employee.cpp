#include "employee.h"
#include "db.h"

Employee::Employee(EmployeeRecord const& rec)
	: id(rec.id)
{

}

double Employee::getBaseRate() const
{
	return DBProcedures::getBaseRateByID(id);
}

int Employee::getWorkExperience() const
{
    return DBProcedures::getWorkExperienceByID(id);
}

double Employee::getManagementCoeff() const
{
	// Always 0, Employee doesnt have other employees
    return 0;
}

double Employee::getExtraPayLimit() const
{
    int position = DBProcedures::getPositionIDByName("Employee");
    return DBProcedures::getExtraPayLimitByPosition(position);
}

double Employee::getExperienceCoeff() const
{
	int position = DBProcedures::getPositionIDByName("Employee");
	return DBProcedures::getExperienceCoeffByPosition(position);
}

double Manager::getBaseRate() const
{
	return 0.0;
}

double Manager::getExperienceCoeff() const
{
	return 0.0;
}

int Manager::getWorkExperience() const
{
	return 0;
}

double Manager::getManagementCoeff() const
{
	return 0.0;
}

double Manager::getExtraPayLimit() const
{
	return 0.0;
}

double Sales::getBaseRate() const
{
	return 0.0;
}

double Sales::getExperienceCoeff() const
{
	return 0.0;
}

int Sales::getWorkExperience() const
{
	return 0;
}

double Sales::getManagementCoeff() const
{
	return 0.0;
}

double Sales::getExtraPayLimit() const
{
	return 0.0;
}

double Employee::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Manager::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Sales::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}
