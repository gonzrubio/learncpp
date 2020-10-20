#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D(const double x, const double y, const double z)
	: m_x{ x }, m_y{ y }, m_z{ z } {}

void Vector3D::print() const {
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}