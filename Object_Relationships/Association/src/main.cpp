/*
Unlike object composition relationships, in an association, there is no implied
whole/part relationship.

Unlike a composition or aggregation, where the part is a part of the whole object,
in an association, the associated object is otherwise unrelated to the object.
Just like an aggregation, the associated object can belong to multiple objects
simultaneously, and isn’t managed by those objects. However, unlike an aggregation,
where the relationship is always unidirectional, in an association, the relationship
may be unidirectional or bidirectional (where the two objects are aware of each other).

We can say that association models as “uses-a” relationship. The doctor “uses” the
patient (to earn income). The patient uses the doctor (for whatever health purpose).

Most often, associations are implemented using pointers, where the object points
at the associated object.
*/

#include "Doctor.h"
#include "Patient.h"
#include <iostream>

void doctor_patient() {
	// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.add_patient(dave);

	scott.add_patient(dave);
	scott.add_patient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';
}

int main() {
	doctor_patient(); // bi-directional relationship.
}