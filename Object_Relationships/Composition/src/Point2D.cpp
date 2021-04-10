#include "Point2D.h"

std::ostream& operator<<(std::ostream& out, const Point2D& point) {
	out << "(" << point.m_x << ", " << point.m_y << ")";
	return out;
}

void Point2D::set_point(int x, int y) {
	m_x = x;
	m_y = y;
}
