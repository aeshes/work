#ifndef DB_HXX
#define DB_HXX

#include <QtSql>
#include <QDebug>


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

class DBProcedures
{
public:
    DBProcedures();

public:
    static int getWorkExperienceByID(int id);
};

#endif // DB_HXX
