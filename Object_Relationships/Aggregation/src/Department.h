#pragma once
#include "Teacher.h"
#include <functional>
#include <vector>

class Department {
private:
	std::vector<std::reference_wrapper<const Teacher>> m_teachers;
public:
	Department() {}
	void add(const Teacher &teacher);
	friend std::ostream& operator<<(std::ostream &out, const Department &department);
};

