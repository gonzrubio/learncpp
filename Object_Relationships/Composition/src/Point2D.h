#pragma once
#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>

class Point2D {
private:
	int m_x;
	int m_y;
public:
	//Default constructor.
	Point2D() : m_x{ 0 }, m_y{ 0 } {}
	// A specific constructor.
	Point2D(int x, int y) : m_x{ x }, m_y{ y } {}
	// Setter method.
	void set_point(int x, int y);
	// Overloaded << operator. Return by reference to allow chaining operatrions.
	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
};

#endif

