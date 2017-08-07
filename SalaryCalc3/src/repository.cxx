#include "repository.hxx"

EmployeeRepository::EmployeeRepository(
        std::shared_ptr<database> const& db
        )
    : AbstractRepository(db)
{
    // Nothing
}

bool EmployeeRepository::check_position(int id)
{
    typedef odb::query<position> pos_query;

    try
    {
        odb::transaction t(db->begin());
        std::shared_ptr<position> p(db->query_one<position>(pos_query::employee_id == id));
        t.commit();

        return p->department_id->id == 1;
    }
    catch (const odb::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return false;
}

EmployeeRepository::value_type EmployeeRepository::select(int id)
{
    typedef odb::query<Employee> query;

    try
    {
        if (check_position(id))
        {
            odb::transaction t(db->begin());

            std::shared_ptr<Employee> emp(db->query_one<Employee>(query::id == id));

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
