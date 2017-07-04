#include "salary.h"

double Dispatcher::dispatch(Employee &emp)
{
    double extra_pay_percents = emp.exp_coeff * emp.work_exp;
    double extra_pay = extra_pay_percents < emp.extra_pay_limit ? emp.base_rate * extra_pay_percents
                                                                                                         : emp.base_rate * emp.extra_pay_limit;
    return emp.base_rate + extra_pay;
}

double Dispatcher::dispatch(Manager &man)
{
    return 0.0;
}

double Dispatcher::dispatch(Sales &sal)
{
    return 0.0;
}
