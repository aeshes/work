#include "gmock\gmock.h"
#include "composite.h"

using ::testing::Eq;

TEST(EmployeeHaruhi, SalaryForHaruhi)
{
	Employee employee(1);
	ASSERT_THAT(employee.salary(), Eq(50.0));
}

TEST(EmployeeAsuka, SalaryForAsuka)
{
	Employee employee(2);
	ASSERT_THAT(employee.salary(), Eq(54.5));
}

TEST(EmployeeShana, SalaryForShana)
{
	Employee employee(3);
	ASSERT_THAT(employee.salary(), Eq(56.0));
}


class EmployeeStub : public Employee
{
public:
	using Employee::Employee;
	using Employee::baseRate;
	using Employee::workExperience;
	using Employee::extraPercents;
	using Employee::percentsPerYear;
	using Employee::extraPay;
};

TEST(EmployeeHaruhi, BaseRateForHaruhi)
{
	EmployeeStub e(1);
	ASSERT_THAT(e.baseRate(), Eq(50.0));
}

TEST(EmployeeShana, WorkExpForShana)
{
	EmployeeStub e(3);
	ASSERT_THAT(e.workExperience(), Eq(4));
}

TEST(EmployeeShana, ExtraPercentsForShana)
{
	EmployeeStub e(3);
	ASSERT_THAT(e.extraPercents(), Eq(0.12));
}

TEST(EmployeeShana, PercentsPerYearForShana)
{
	EmployeeStub e(3);
	ASSERT_THAT(e.percentsPerYear(), Eq(0.03));
}

TEST(EmployeeShana, ExtraPayForShana)
{
	EmployeeStub e(3);
	ASSERT_THAT(e.extraPay(), Eq(6.0));
}