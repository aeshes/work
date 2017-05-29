#include "core.h"

double employee::salary() const
{
	double extra_pay_percents = 0.03 * work_experience();
	double extra_pay = extra_pay_percents < 0.3 ? base_rate * extra_pay_percents
												: base_rate * 0.3;
	return base_rate + extra_pay;
}

unsigned employee::work_experience() const
{
	return 0;
}

double manager::salary() const
{
	double extra_pay_percents = 0.03 * work_experience();
	double extra_pay = extra_pay_percents < 0.4 ? base_rate * extra_pay_percents
												: base_rate * 0.4;
	double salary_of_subordinates = 0;
	std::for_each(subordinates.begin(), subordinates.end(),
		[&salary_of_subordinates](typename storage_type::const_reference sub)
		{
			salary_of_subordinates += sub->salary();
		});
	return base_rate + extra_pay + 0.005 * salary_of_subordinates;
}

unsigned manager::work_experience() const
{
	return 0;
}

double sales::salary() const
{
	double extra_pay_percents = 0.01 * work_experience();
	double extra_pay = extra_pay_percents < 0.35 ? base_rate * extra_pay_percents
												 : base_rate * 0.35;
	double salary_of_subordinates = 0;
	std::for_each(subordinates.begin(), subordinates.end(),
		[&salary_of_subordinates](typename storage_type::const_reference sub)
	{
		salary_of_subordinates += sub->salary();
	});
	return base_rate + extra_pay + 0.003 * salary_of_subordinates;
	return 0;
}

unsigned sales::work_experience() const
{
	return 0;
}