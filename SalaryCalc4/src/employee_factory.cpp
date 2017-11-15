#include "employee_factory.h"

#include "employee.h"


QSharedPointer<AbstractEmployee>
EmployeeFactory::makeEmployee(EmployeeRecord const& rec)
{
	switch (rec.position)
	{
	case POSITION::EMPLOYEE:
		return QSharedPointer<AbstractEmployee>(new Employee(rec));
		break;
	case POSITION::MANAGER:
		return QSharedPointer<AbstractEmployee>(new Manager(rec));
		break;
	case POSITION::SALES:
		return QSharedPointer<AbstractEmployee>(new Sales(rec));
		break;
	default: break;
	}

	return QSharedPointer<AbstractEmployee>(nullptr);
}