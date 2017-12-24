#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QVariant>


class DBConnection
{
public:
	static DBConnection& connect()
	{
		static DBConnection inst;
		return inst;
	}

private:
	DBConnection();
	DBConnection(const DBConnection&) = delete;
	DBConnection& operator=(const DBConnection&) = delete;

	static QSqlDatabase db;
};

namespace db
{
	QVariant selectSingleFieldFromTableByID(QString const& table, QString const& field, qint64 id);

	double selectExperienceByID(qint64 id);
}

#endif
