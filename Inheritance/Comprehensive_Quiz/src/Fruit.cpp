#include "Fruit.h"

Fruit::Fruit(const std::string& name, const std::string& color) :
	m_name{ name }, m_color{ color }
{
}

const std::string& Fruit::get_name() const {
	return m_name;
}

const std::string& Fruit::get_color() const {
	return m_color;
}
