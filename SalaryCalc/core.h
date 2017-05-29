#ifndef CORE_H
#define CORE_H

#include <string>
#include <set>
#include <algorithm>
#include <memory>

// јбстрактный класс дл€ всех сотрудников
class worker
{
public:
	worker() = default;
	worker(std::string & _name, unsigned _base_rate, unsigned _date)
		: name(_name), base_rate(_base_rate), enrollment_date(_date) {}
	virtual ~worker() = default;

	virtual double salary() const = 0;
	virtual unsigned work_experience() const = 0;

protected:
	std::string name;
	unsigned base_rate;
	unsigned enrollment_date;
	unsigned worker_id;
};

// јбстрактный базовый класс дл€ сотрудников, которые могут иметь подчиненных
class head : public worker
{
public:
	head() = default;

protected:
	// Ќабор подчиненных (указатели на классы, описывающие произвольного работника)
	typedef std::set<std::shared_ptr<worker>> storage_type;
	storage_type subordinates;
};

// Employee не может иметь подчиненных
class employee : public worker
{
public:
	employee() = default;
	double   salary()            const override;
	unsigned work_experience()   const override;
};

class manager : public head
{
public:
	manager() = default;
	double   salary()            const override;
	unsigned work_experience()   const override;
};

class sales : public head
{
public:
	sales();
	double   salary()            const override;
	unsigned work_experience()   const override;
};

#endif