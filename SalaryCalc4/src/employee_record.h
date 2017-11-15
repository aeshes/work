#ifndef EMPLOYEE_RECORD_H
#define EMPLOYEE_RECORD_H

#include <QString>
#include <QDate>

struct EmployeeRecord
{
	qint64  id;
	QString firstName;
	QString lastName;
	double  baseRate;
	QDate   hireDate;
	qint64  position;
	qint64  superior;
};

EmployeeRecord getEmployeeRecord(qint64 id);

#endif