#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <memory>
#include <vector>
#include <cassert>

/* Base abstract class with behaviour common for all primitive and composite objects*/
class Component
{
public:
	virtual double salary() const = 0;
	virtual void add(Component *)
	{
		assert(false);	/* Do not call 'add' method for primitive types */
	}
	virtual ~Component() = default;
};


/* Primitive class Employee. Can't contain other employees*/
class Employee : public Component
{
public:
	Employee(unsigned id);
	double salary() const override;

protected:
	double baseRate() const;
	double workExperience() const;
	double extraPercents() const;
	double percentsPerYear() const;
	double extraPay() const;

	unsigned id;
};


/* Composite class Manager. Can contain any subclasses of Component class */
class Manager : public Component
{
public:
	Manager(unsigned id);
	~Manager();
	double salary() const override;
	void add(Component *c) override;

protected:
	double extraPay() const;
	double baseRate() const;
	double workExperience() const;
	double payForEmployees() const;

private:
	std::vector<Component *> employees;
	unsigned id;
};


/* Composite class Sales. Can contain any subclasses of Component class */
class Sales : public Component
{
public:
	double salary() const override;
	void add(Component *c) override;

private:
	std::vector<Component *> employees;
};

#endif