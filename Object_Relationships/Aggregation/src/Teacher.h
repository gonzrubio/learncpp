#pragma once
#include <string>

class Teacher {
private:
	std::string m_name;
public:
	Teacher(const std::string &name) : m_name{name} {}
	const std::string get_name() const { return m_name; }
};

