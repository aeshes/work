#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QtSql>

#include "db.h"
#include "employee.h"


class EmployeeDAO
{
public:
    EmployeeDAO();

    int selectWorkExperience(int id);
};

class EmployeeRepository
{
public:
    EmployeeRepository();

    Employee select(int id);
    void create();
    void update();
    void remove();
};

#endif // REPOSITORY_H
