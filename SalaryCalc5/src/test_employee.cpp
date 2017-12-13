#include "gmock\gmock.h"
#include "employee.h"


using ::testing::Eq;

TEST(EmployeeSalary, SalaryForHaruhiReturnsRightValue)
{
	Employee employee(1);
	ASSERT_THAT(employee.salary(), Eq(50.0));
}

TEST(EmployeeSalary, SalaryForShanaReturnsRightValue)
{
	Employee employee(3);
	ASSERT_THAT(employee.salary(), Eq(56.0));
}


class EmployeeMethods : public Employee
{
public:
	using Employee::Employee;
	using Employee::baseRate;
	using Employee::workExperience;
	using Employee::extraPercents;
	using Employee::percentsPerYear;
};

TEST(Employee, BaseRateForHaruhi)
{
	EmployeeMethods e(1);
	ASSERT_THAT(e.baseRate(), Eq(50.0));
}

TEST(Employee, WorkExpForShana)
{
	EmployeeMethods e(3);
	ASSERT_THAT(e.workExperience(), Eq(4));
}

TEST(Employee, ExtraPercentsForShana)
{
	EmployeeMethods e(3);
	ASSERT_THAT(e.extraPercents(), Eq(0.12));
}

TEST(Employee, PercentsPerYearForShana)
{
	EmployeeMethods e(3);
	ASSERT_THAT(e.percentsPerYear(), Eq(0.03));
}

