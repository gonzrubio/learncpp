#pragma once
#include <string>

class Person {
public:
	std::string m_name{};
	int m_age{};
	Person() = default;
	Person(const std::string& name, int age);
	const std::string& get_name() const;
	const int get_age() const;
};

