#include "salary.h"

double Dispatcher::dispatch(Employee & emp)
{
    double extraPayPercents = emp.getExperienceCoeff() * emp.getWorkExperience();
    double extraPay = 0;
    if (extraPayPercents < emp.getExtraPayLimit())
    {
        extraPay = emp.getBaseRate() * extraPayPercents;
    }
    else
    {
        extraPay = emp.getBaseRate() * emp.getExtraPayLimit();
    }
    return emp.getBaseRate() + extraPay;
}

double Dispatcher::dispatch(Manager &man)
{
    return 0;
}

double Dispatcher::dispatch(Sales &sal)
{
    return 0.0;
}
