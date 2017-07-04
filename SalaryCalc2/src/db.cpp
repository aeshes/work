#include "db.h"

const QString DEFAULT_DB_NAME("data.db");


DBConnection::DBConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DEFAULT_DB_NAME);

    if (!db.open())
    {
        qDebug() << "Unable to open database" << db.lastError();
    }
}

QSqlDatabase DBConnection::db;
