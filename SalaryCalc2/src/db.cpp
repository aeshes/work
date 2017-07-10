#include "db.h"

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



QueryHandler::QueryHandler()
{
    start();
}

void QueryHandler::run()
{
    DBConnection::connect();

    while (true)
    {
        if (!sql_queue.empty())
        {
            auto msg = sql_queue.dequeue();
            if (msg.query.exec())
            {
                msg.query.next();
                msg.result(msg.query);
            }
            else qDebug()  << msg.query.lastError();
        }
        else msleep(10);
    }
}

void QueryHandler::push(sql_msg &query)
{
    sql_queue.push_back(query);
}

static QueryHandler handler;

QString get_name(int id)
{
    QSqlQuery query;
    QString sql = "SELECT firstname FROM employee WHERE id = " + QString::number(id);
    query.prepare(sql);

    auto callback = [&query](QSqlQuery &q) { query = q; };
    sql_msg msg = { query, callback };
    handler.push(msg);

    return query.value(0).toString();
}
