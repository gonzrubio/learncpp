#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include "Point2D.h"

class Creature {
private:
	std::string m_name;
	Point2D m_location;
public:
	// Constructor.
	Creature(const std::string &name, const Point2D &location) :
		m_name{ name }, m_location{ location }
	{
	}
	// Overloaded << operator.
	friend std::ostream& operator<<(std::ostream& out, const Creature& creature);
	// Setter method.
	void move_to(int x, int y);
};

#endif

