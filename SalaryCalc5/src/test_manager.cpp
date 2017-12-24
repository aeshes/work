#include "gmock\gmock.h"
#include "composite.h"


using ::testing::Eq;

TEST(ManagerSalary, SalaryForShiki)
{
	Manager m(4);

	m.add(new Employee(1));
	m.add(new Employee(2));

	ASSERT_THAT(m.salary(), Eq(53.0225));
}

class ManagerStub : public Manager
{
public:
	using Manager::Manager;
	using Manager::extraPay;
	using Manager::payForEmployees;
	using Manager::baseRate;
	using Manager::workExperience;
};

TEST(ManagerMethods, baseRate)
{
	ManagerStub m(4);
	ASSERT_THAT(m.baseRate(), Eq(50.0));
}

TEST(ManagerMethods, workExperience)
{
	ManagerStub m(4);
	ASSERT_THAT(m.workExperience(), Eq(1));
}

TEST(ManagerMethods, payForEmployees)
{
	ManagerStub m(4);

	m.add(new Employee(1));
	m.add(new Employee(2));

	ASSERT_THAT(m.payForEmployees(), Eq(0.5225));
}

TEST(ManagerMethods, extraPay)
{
	ManagerStub m(4);

	m.add(new Employee(1));
	m.add(new Employee(2));

	ASSERT_THAT(m.extraPay(), Eq(3.0225));
}