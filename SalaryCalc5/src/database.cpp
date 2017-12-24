#include "database.h"

#include <QDebug>


const QString DEFAULT_DB_NAME("data\\data.db");


DBConnection::DBConnection()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(DEFAULT_DB_NAME);

	if (!db.open())
	{
		qDebug() << "In DBConenction: Unable to open database"
			<< db.lastError();
	}
}

QSqlDatabase DBConnection::db;


namespace db
{
	QVariant selectSingleFieldFromTableByID(QString const& table, QString const& field, qint64 id)
	{
		QSqlQuery q("SELECT " + field + " FROM " + table + " WHERE id = " + QString::number(id));

		if (q.next())
		{
			return q.value(0);
		}
		return QVariant();
	}

	double selectExperienceByID(qint64 id)
	{
		QSqlQuery q("SELECT DATE('now') - (SELECT hire_date FROM employee " \
			" WHERE id = " + QString::number(id) + ")");
		if (q.next())
		{
			return q.value(0).toInt();
		}
		return 0.0;
	}
}