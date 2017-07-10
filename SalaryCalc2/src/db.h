#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QString>
#include <QDebug>
#include <QQueue>
#include <QThread>
#include <QObject>

#include <memory>
#include <functional>


class DBConnection : public QObject
{
    Q_OBJECT

    static QSqlDatabase db;

public:
    static DBConnection& connect()
    {
        static DBConnection inst;
        return inst;
    }

    static DBConnection* getInstance()
    {
        return &connect();
    }

public slots:
    void execute(QString);

private:
    DBConnection();
    DBConnection(const DBConnection&);
    DBConnection& operator=(const DBConnection&);
};

void __sql_callback_(QSqlQuery&);

typedef struct _sql_msg
{
    QSqlQuery query;
    std::function<decltype(__sql_callback_)> result;
} sql_msg;

class QueryHandler : public QThread
{
    Q_OBJECT
public:
    QueryHandler();
    void run();

public slots:
    void push(sql_msg &query);

private:
    QQueue<sql_msg> sql_queue;
};

inline QueryHandler& getQueryHandler()
{
    static QueryHandler h;
    return h;
}

inline void update(int id, double value)
{
    auto& handler  = getQueryHandler();
    auto callback = [](QSqlQuery&){ qDebug() << "msg accepted!"; };

    QSqlQuery query;
    query.prepare("UPDATE employee SET base_rate = :value WHERE id = :id");
    query.bindValue(":value", QVariant(value));
    query.bindValue(":id",       QVariant(id));

    sql_msg msg = { query, callback };
    handler.push(msg);
}

template <typename ReturnType>
ReturnType fetch(QSqlQuery &sql, bool *ok = 0)
{
    ReturnType ret;
    auto handler  = getQueryHandler();
    auto callback = [&ret](ReturnType param)
    {
        ret =  param;
    };
    sql_msg msg = { sql, callback };
    handler.push(msg);
}

QString get_name(int id);


#endif // DB_H
