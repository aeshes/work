#include "employee.hxx"

std::ostream& operator<<(std::ostream& os, const employee& e)
{
    os << e.firstname << std::endl;
    os << e.lastname << std::endl;
}

double employee::getBaseRate() const
{
    return base_rate;
}

double employee::getWorkExperience() const
{
    return 0;
}

double employee::getManagementCoeff() const
{
    return 0;
}

double employee::getExtraPayLimit() const
{
    return 0;
}

double employee::getExperienceCoeff() const
{
    return 0;
}



double manager::getBaseRate() const
{
    return base_rate;
}

double manager::getWorkExperience() const
{
    return 0;
}

double manager::getManagementCoeff() const
{
    return 0;
}

double manager::getExtraPayLimit() const
{
    return 0;
}

double manager::getExperienceCoeff() const
{
    return 0;
}

double sales::getBaseRate() const
{
    return base_rate;
}

double sales::getWorkExperience() const
{
    return 0;
}

double sales::getManagementCoeff() const
{
    return 0;
}

double sales::getExtraPayLimit() const
{
    return 0;
}

double sales::getExperienceCoeff() const
{
    return 0;
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
