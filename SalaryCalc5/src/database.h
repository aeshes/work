#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class DBConnection
{
		static QSqlDatabase db;
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
};

#endif
