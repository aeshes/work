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