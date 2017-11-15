#include "employee_record.h"

#include <QtSql>


EmployeeRecord getEmployeeRecord(qint64 id)
{
	QSqlQuery q("SELECT * FROM employee WHERE id = " + QString::number(id));

	if (q.next())
	{
		EmployeeRecord rec =
		{
			q.value(0).toInt(),
			q.value(1).toString(),
			q.value(2).toString(),
			q.value(3).toDouble(),
			q.value(4).toDate(),
			q.value(5).toInt(),
			q.value(6).toInt()
		};
		return rec;
	}
	return EmployeeRecord();
}