#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QtSql>

#include "db.h"
#include "employee.hxx"

#include "odb-inc.hxx"
#include "employee-odb.hxx"

using odb::database;

template <class employee_type>
class employee_repository
{
    std::shared_ptr<database> db;

public:
    employee_repository(std::shared_ptr<database> const& db);

    std::shared_ptr<employee_type> select(int id);
    void create();
    void update();
    void remove();

private:
    bool check_position(int id);
};

template <class EmployeeType>
employee_repository<EmployeeType>::employee_repository(std::shared_ptr<database> const& db)
    : db(db)
{
    // Nothing
}

template <class T>
bool employee_repository<T>::check_position(int id)
{
    typedef odb::query<position> pos_query;

    try
    {
        odb::transaction t(db->begin());
        std::shared_ptr<position> p(db->query_one<position>(pos_query::employee_id == id));
        t.commit();

        return p->department_id->id == T::type;
    }
    catch (const odb::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template <class EmployeeType>
std::shared_ptr<EmployeeType> employee_repository<EmployeeType>::select(int id)
{
    typedef odb::query<EmployeeType> query;
    typedef odb::query<position> pos_query;

    try
    {
        if (check_position(id))
        {
            odb::transaction t(db->begin());

            std::shared_ptr<EmployeeType> emp(db->query_one<EmployeeType>(query::id == id));

            t.commit();
            return emp;
        }
        return nullptr;
    }
    catch (odb::exception const& e)
    {
        std::cout << "In employee_repository::select : " << e.what() << std::endl;
    }

    return nullptr;
}

#endif // REPOSITORY_H
