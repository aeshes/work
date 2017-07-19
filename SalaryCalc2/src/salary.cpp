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
    double extra_pay_percents = man.exp_coeff * man.work_exp;
    double extra_pay = extra_pay_percents < man.extra_pay_limit ? man.base_rate * extra_pay_percents
                                                                                                        : man.base_rate * man.extra_pay_limit;
    double total_employee_salary = 0;
    for (auto& it : man.employees)
    {
        total_employee_salary += it.salary(*this);
    }
    return man.base_rate + extra_pay + man.emp_coeff * total_employee_salary;
}

double Dispatcher::dispatch(Sales &sal)
{
    return 0.0;
}
