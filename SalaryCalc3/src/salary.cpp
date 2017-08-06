#include "salary.hxx"

double Dispatcher::dispatch(Employee &emp)
{
    double extra_pay_percents = emp.getExperienceCoeff() * emp.getWorkExperience();
    double extra_pay = 0;
    if (extra_pay_percents < emp.getExtraPayLimit())
    {
        extra_pay = emp.getBaseRate() * extra_pay_percents;
    }
    else
    {
        extra_pay = emp.getBaseRate() * emp.getExtraPayLimit();
    }
    return emp.getBaseRate() + extra_pay;
}

double Dispatcher::dispatch(Manager &man)
{
    return 0;
}

double Dispatcher::dispatch(Sales &sal)
{
    return 0.0;
}
