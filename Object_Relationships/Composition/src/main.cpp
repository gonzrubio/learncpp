/*
Object composition is the process of building complex objects from simpler ones.
Object composition models "has a" relationships between two objects.

Compositions are typically created as structs or classes with normal data members.
Because these data members exist directly as part of the struct/class, their lifetimes
are bound to that of the class instance itself.

Compositions that need to do dynamic allocation or deallocation may be implemented using
pointer data members. In this case, the composition class should be responsible for doing
all necessary memory management itself (not the user of the class).

Classes designed using composition are straightforward, flexible, and robust (in that they
clean up after themselves nicely). The composition should manage its parts without the user
of the composition needing to manage anything.

A good rule of thumb is that each class should be built to accomplish a single task.
That task should either be the storage and manipulation of some kind of data (e.g. Point2D,
std::string), OR the coordination of subclasses (e.g. Creature). Ideally not both.
*/

#include "Creature.h"
#include "Point2D.h"
#include <iostream>

void test_creature() {
	Point2D point{ 4, 20 };
	std::cout << point << std::endl;

	Creature creature1{ "creature_1", Point2D{69, 69} };
	std::cout << creature1 << std::endl;

	Creature creature2{ "creature_2", point };
	std::cout << creature2 << std::endl;
}

int main() {
	// test_creature();

	std::cout << "Enter a name for your creature:" << std::endl;
	std::string name;
	std::cin >> name;
	Creature creature{ name, Point2D{} };
	std::cout << creature << std::endl;
	
	while (true) {

		std::cout << "Enter a new x-coordinate for your creature (-1 to quit):" << std::endl;
		int x{};
		std::cin >> x;
		if (x == -1) { break; }

		std::cout << "Enter a new y-coordinate for your creature (-1 to quit):" << std::endl;
		int y{};
		std::cin >> y;
		if (y == -1) { break; }

		creature.move_to(x, y);
		std::cout << creature << std::endl;
	}

}