#include "Department.h"
#include <iostream>

void Department::add(const Teacher& teacher) {
	m_teachers.push_back(teacher);
}

std::ostream& operator<<(std::ostream& out, const Department& department) {
	out << "Department: " ;
	for (const auto &teacher : department.m_teachers) {
		out << " " << teacher.get().get_name() ;
	}
	out << std::endl;
	return out;
}
