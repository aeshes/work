#include "db.hxx"

const QString DEFAULT_DB_NAME("data.db");


DBConnection::DBConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DEFAULT_DB_NAME);

    if (!db.open())
    {
        qDebug() << "Unable to open database"
                 << db.lastError();
    }
}

void DBConnection::execute(QString sql)
{
    QSqlQuery query(sql);
    query.exec();
    qDebug() << "executed";
}

QSqlDatabase DBConnection::db;


DBProcedures::DBProcedures()
{
    // Connect to database before using this class
}

int DBProcedures::getWorkExperienceByID(int id)
{
    QSqlQuery q("SELECT DATE('now') - (SELECT hire_date FROM employee " \
                " WHERE id = " + QString::number(id) + ")");
    if (q.next())
    {
        return q.value(0).toInt();
    }
    return 0;
}
