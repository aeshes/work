#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class IEmployee
{
public:
	virtual double salary() const = 0;
};

class Employee : public IEmployee
{
public:
	Employee() = default;
	Employee(unsigned id);
	double salary() const override;

protected:
	double baseRate() const;
	double workExperience() const;
	double extraPercents() const;
	double percentsPerYear() const;
	double extraPay(double base, double percents) const;

	unsigned id;
};

#endif
