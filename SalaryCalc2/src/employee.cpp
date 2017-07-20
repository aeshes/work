#include "employee.h"

AbstractEmployee::AbstractEmployee(int id)
    : id(id)
{
    init(id);
    initWorkExp(id);
}

AbstractEmployee::AbstractEmployee
(
        int     id,
        QString fname,
        QString lname,
        QDate   hired,
        double  rate,
        int     exp
)
    : id(id), firstname(fname), lastname(lname),
      hire_date(hired), base_rate(rate), work_exp(exp)
{}

double AbstractEmployee::onGetBaseRate()
{
    return get<double>("base_rate", id);
}

int AbstractEmployee::onGetWorkExperience()
{
    QString sql = "SELECT DATE('now') - (SELECT hire_date FROM employee WHERE id = "
                + QString::number(id) + ")";
    QSqlQuery query(sql);
    if (query.next())
    {
        return query.value(0).toInt();
    }
    return 0;
}

double AbstractEmployee::onGetManagementCoeff()
{
    return 0;
}

double AbstractEmployee::onGetExtraPayLimit()
{
    return 0;
}

double AbstractEmployee::onGetExperienceCoeff()
{
    return 0;
}

void AbstractEmployee::init(int id)
{
    QSqlQuery query;
    QString sql = "SELECT firstname, lastname, hire_date, base_rate "
                  "FROM employee "
                  "WHERE id = " + QString::number(id);
    if (!query.exec(sql))
    {
        qDebug() << "Unable to select data from employee table"
                 << query.lastError();
    }

    this->id = id;
    QSqlRecord rec = query.record();
    if (query.next())
    {
        firstname = query.value(rec.indexOf("firstname")).toString();
        lastname  = query.value(rec.indexOf("lastname")).toString();
        hire_date = query.value(rec.indexOf("hire_date")).toDate();
        base_rate = query.value(rec.indexOf("base_rate")).toDouble();
    }
}

void AbstractEmployee::initWorkExp(int id)
{
    QSqlQuery query;
    QString sql = "SELECT DATE('now') - (SELECT hire_date FROM employee WHERE id = "
                + QString::number(id) + ")";
    query.exec(sql);
    if (query.next())
    {
        work_exp = query.value(0).toInt();
    }
}

void Employee::debug()
{
    qDebug() << "firstname: " << firstname;
    qDebug() << "lastname: "  << lastname;
    qDebug() << "hire_date: " << hire_date;
    qDebug() << "base_rate: " << base_rate;
    qDebug() << "exp: "       << work_exp;
}

Employee::Employee(int id)
    : AbstractEmployee(id)
{}

double Employee::getBaseRate() const
{
    return base_rate;
}

double Employee::getWorkExperience() const
{
    return work_exp;
}

double Employee::getManagementCoeff() const
{
    return 0;
}

double Employee::getExtraPayLimit() const
{
    return extra_pay_limit;
}

double Employee::getExperienceCoeff() const
{
    return exp_coeff;
}

LazyEmployeeList::LazyEmployeeList(int id)
    : _id(id), loaded(false)
{

}

void LazyEmployeeList::load_from_db(int id)
{
    QString sql = "SELECT id FROM employee WHERE superior = " + QString::number(id);
    QSqlQuery query(sql);
    while (query.next())
    {
        int emp_id = query.value(0).toInt();
        lazy.push_back(Employee(emp_id));
    }
}

QList<Employee>::iterator LazyEmployeeList::begin()
{
    if (!loaded)
    {
        load_from_db(_id);
        loaded = true;
    }
    return lazy.begin();
}

QList<Employee>::iterator LazyEmployeeList::end()
{
    if (!loaded)
    {
        load_from_db(_id);
        loaded = true;
    }
    return lazy.end();
}

Manager::Manager(int id)
    : AbstractEmployee(id), employees(LazyEmployeeList(id))
{
    for (auto it = employees.begin(); it != employees.end(); ++it)
    {
        Dispatcher dispatcher;
        qDebug() << it->salary(dispatcher);
    }
}

double Manager::getBaseRate() const
{
    return base_rate;
}

double Manager::getWorkExperience() const
{
    return work_exp;
}

double Manager::getManagementCoeff() const
{
    return emp_coeff;
}

double Manager::getExtraPayLimit() const
{
    return extra_pay_limit;
}

double Manager::getExperienceCoeff() const
{
    return exp_coeff;
}

double Sales::getBaseRate() const
{
    return base_rate;
}

double Sales::getWorkExperience() const
{
    return work_exp;
}

double Sales::getManagementCoeff() const
{
    return 0;
}

double Sales::getExtraPayLimit() const
{
    return 0;
}

double Sales::getExperienceCoeff() const
{
    return 0;
}

double Employee::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Manager::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}

double Sales::salary(AbstractDispatcher & dispatcher)
{
    return dispatcher.dispatch(*this);
}
