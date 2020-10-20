#include "Point2d.h"
#include <cmath>
#include <iostream>

void Point2d::print() {
	std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

double distanceFrom(const Point2d& p1, const Point2d& p2) {
	return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}