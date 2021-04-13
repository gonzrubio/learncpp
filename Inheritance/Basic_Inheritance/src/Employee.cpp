#include "Employee.h"
#include <iostream>

Employee::Employee(double hourly_salary, long employee_ID) :
	m_hourly_salary{ hourly_salary }, m_employee_ID{ employee_ID } {

}

void Employee::print_name_and_salary() const {
	std::cout << m_name << ": " << m_hourly_salary << '\n';
}
