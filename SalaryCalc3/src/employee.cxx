#include "employee.hxx"
#include "db.hxx"

double AbstractEmployee::getBaseRate() const
{
    return base_rate;
}

int AbstractEmployee::getWorkExperience() const
{
    return DBProcedures::getWorkExperienceByID(id);
}

std::string AbstractEmployee::name() const
{
    return firstname + " " + lastname;
}


int Employee::getWorkExperience() const
{
    return DBProcedures::getWorkExperienceByID(id);
}

double Employee::getManagementCoeff() const
{
    return 0;   // Always 0, Employee doesnt have other employees
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
