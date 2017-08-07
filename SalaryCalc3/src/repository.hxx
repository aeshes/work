#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QtSql>

#include "db.h"
#include "employee.hxx"

#include "odb-inc.hxx"
#include "employee-odb.hxx"

using odb::database;

class AbstractRepository
{
public:
    using value_type =  std::shared_ptr<AbstractEmployee>;

public:
    virtual value_type select(int id) = 0;
    virtual void create() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;

protected:
    AbstractRepository(std::shared_ptr<database> db)
        : db(db) { /*Nothing */ }

protected:
    std::shared_ptr<database> db;
};

class EmployeeRepository : public AbstractRepository
{
public:
    EmployeeRepository(
            std::shared_ptr<database> const& db
            );

    value_type select(int id);
    void create() {}
    void update() {}
    void remove() {}

private:
    bool check_position(int id);
};

#endif // REPOSITORY_H
