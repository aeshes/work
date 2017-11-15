#ifndef EMPLOYEE_FACTORY_H
#define EMPLOYEE_FACTORY_H

#include <QSharedPointer>
#include "employee.h"

class AbstractEmployee;
class EmployeeRecord;


class IEmployeeFactory
{
public:
	virtual QSharedPointer<AbstractEmployee> makeEmployee(EmployeeRecord const& rec) = 0;
};

class EmployeeFactory : public IEmployeeFactory
{
	enum POSITION
	{
		EMPLOYEE = 1, MANAGER, SALES
	};
public:
	QSharedPointer<AbstractEmployee> makeEmployee(EmployeeRecord const& rec) override;
};

#endif