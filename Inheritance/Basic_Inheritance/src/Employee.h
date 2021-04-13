#pragma once
#include "Person.h"

class Employee : public Person {
public:
	double m_hourly_salary{};
	long m_employee_ID{};
	Employee(double hourly_salary = 0.0, long employee_ID = 0);
	void print_name_and_salary() const;
};

