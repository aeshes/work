#include "TestEmployee.h"
#include "employee.h"

#include <qDebug>
#include <cmath>
#include <limits>

static bool is_equal(double x, double y)
{
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

void TestEmployee::testGetBaseRate()
{
	Employee emp(1);
	auto baseRate = emp.getBaseRate();
	Q_ASSERT_X(baseRate == 50.0, "testGetBaseRate", "Incorrect baseRate for Employee");
	qDebug() << "TEST Employee::getBaseRate OK";
}

void TestEmployee::testGetWorkExperience()
{
	Employee emp(1);
	auto workExp = emp.getWorkExperience();
	Q_ASSERT_X(workExp == 0, "testGetWorkexperience", "Incorrect workExperience for Employee");
	qDebug() << "TEST Employee::getWorkExperience OK";
}

void TestEmployee::testGetManagementCoeff()
{
	Employee emp(1);
	auto managementCoeff = emp.getManagementCoeff();
	Q_ASSERT_X(managementCoeff == 0.0, "testGetManagementCoeff", "Incorrect management coeff for Employee");
	qDebug() << "TEST Employee::getManagementCoeff OK";
}

void TestEmployee::testGetExtraPayLimit()
{
	Employee emp(1);
	auto extraPayLimit = emp.getExtraPayLimit();
	Q_ASSERT_X(is_equal(extraPayLimit, 0.3), "testGetExtraPayLimit", "Incorrect extra pay limit for Employee");
	qDebug() << "TEST Employee::getExtraPayLimit OK";
}

void TestEmployee::testGetExperienceCoeff()
{
	Employee emp(1);
	auto expCoeff = emp.getExperienceCoeff();
	Q_ASSERT_X(is_equal(expCoeff, 0.03), "testGetExperienceCoeff", "Incorrect experience coeff for Employee");
	qDebug() << "TEST Employee::getExperienceCoeff OK";
}

void TestEmployee::testSalary()
{
	Employee emp(1);
	Dispatcher dispatcher;
	auto salary = emp.salary(dispatcher);
	Q_ASSERT_X(is_equal(salary, 50.0), "testSalary", "Incorrect salary for Employee");
	qDebug() << "TEST Employee::salary OK";
}

void TestEmployee::testAll()
{
	TestEmployee::testGetBaseRate();
	TestEmployee::testGetWorkExperience();
	TestEmployee::testGetManagementCoeff();
	TestEmployee::testGetExtraPayLimit();
	TestEmployee::testGetExperienceCoeff();
	TestEmployee::testSalary();
}