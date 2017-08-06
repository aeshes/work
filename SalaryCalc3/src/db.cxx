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

double DBProcedures::getExtraPayLimitByPosition(int position)
{
    // Select actual (last updated) extra pay limit for given position
    QSqlQuery q("SELECT extra_pay FROM extra_pay_limit_history" \
                " WHERE position = " + QString::number(position) +
                " AND change_date = (SELECT max(change_date) FROM extra_pay_limit_history " \
                " WHERE position = " + QString::number(position) + ")");
    if (q.next())
    {
        return q.value(0).toDouble();
    }
    return 0.0;
}

int DBProcedures::getPositionIDByName(const QString& name)
{
    QSqlQuery q("SELECT id FROM department WHERE name = \'" + name + "\'");
    if (q.next())
    {
        return q.value(0).toInt();
    }
    return 0;
}

double DBProcedures::getExperienceCoeffByPosition(int position)
{
    // Get actual (last updated) coefficient for work experience
    QSqlQuery q("SELECT coeff FROM coeff_for_experience_history " \
                " WHERE position = " + QString::number(position) +
                " AND change_date = " \
                " (SELECT max(change_date) from coeff_for_experience_history " \
                " WHERE position = " + QString::number(position) + ")");
    if (q.next())
    {
        return q.value(0).toDouble();
    }
    return 0.0;
}
