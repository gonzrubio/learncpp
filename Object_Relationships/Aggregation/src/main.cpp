/*
Like a composition, an aggregation is still a part-whole relationship, where the parts are
contained within the whole, and it is a unidirectional relationship. However, unlike a
composition, parts can belong to more than one object at a time, and the whole object is not
responsible for the existence and lifespan of the parts. When an aggregation is created,
the aggregation is not responsible for creating the parts. When an aggregation is destroyed,
the aggregation is not responsible for destroying the parts.

We can say that aggregation models “has-a” relationships. Similar to a composition,
the parts of an aggregation can be singular or multiplicative.

Because aggregations are similar to compositions in that they are both part-whole relationships,
they are implemented almost identically, and the difference between them is mostly semantic.
In a composition, we typically add our parts to the composition using normal member variables
(or pointers where the allocation and deallocation process is handled by the composition class).

In an aggregation, we also add parts as member variables. However, these member variables are
typically either references or pointers that are used to point at objects that have been created
outside the scope of the class. Consequently, an aggregation usually either takes the objects it
is going to point to as constructor parameters, or it begins empty and the subobjects are added
later via access functions or operators.

Because these parts exist outside of the scope of the class, when the class is destroyed,
the pointer or reference member variable will be destroyed (but not deleted). Consequently,
the parts themselves will still exist.

Rule: Implement the simplest relationship type that meets the needs of your program,
not what seems right in real-life.

Summarizing composition and aggregation:

Compositions:
- Typically use normal member variables
- Can use pointer members if the class handles object allocation/deallocation itself
- Responsible for creation/destruction of parts

Aggregations:
- Typically use pointer or reference members that point to or reference objects that live
outside the scope of the aggregate class
- Not responsible for creating/destroying parts
*/

#include "Department.h"
#include "Teacher.h"
#include <iostream>

int main() {
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.get_name() << " still exists!\n";
    std::cout << t2.get_name() << " still exists!\n";
    std::cout << t3.get_name() << " still exists!\n";

}