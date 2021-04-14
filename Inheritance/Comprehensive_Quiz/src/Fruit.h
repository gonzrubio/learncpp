#pragma once
#include <string>

class Fruit {
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(const std::string& name, const std::string& color);
	const std::string& get_name() const;
	const std::string& get_color() const;
};

