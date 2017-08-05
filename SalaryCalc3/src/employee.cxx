#include "employee.hxx"

double abstract_employee::getBaseRate() const
{
    return base_rate;
}

int abstract_employee::getWorkExperience() const
{
    return 0;
}

double abstract_employee::getManagementCoeff() const
{
    return 0;
}

double abstract_employee::getExtraPayLimit() const
{
    return 0;
}

double abstract_employee::getExperienceCoeff() const
{
    return 0;
}

std::string abstract_employee::name() const
{
    return firstname + " " + lastname;
}


double employee::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double manager::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double sales::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}
