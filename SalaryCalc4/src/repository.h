#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QtSql>

#include "db.h"
#include "employee.h"

#include <memory>


class AbstractRepository
{
public:
    using value_type =  std::shared_ptr<AbstractEmployee>;

    virtual value_type select(int id) = 0;
    virtual void create() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;

protected:
    AbstractRepository() { }
};

class EmployeeRepository : public AbstractRepository
{
public:
    EmployeeRepository();

    value_type select(int id);
    void create() {}
    void update() {}
    void remove() {}

private:
    bool check_position(int id);
};

#endif // REPOSITORY_H
