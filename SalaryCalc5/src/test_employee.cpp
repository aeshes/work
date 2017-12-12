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