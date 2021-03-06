/*
A container class is a class designed to hold and organize multiple instances of another type (either another class,
or a fundamental type, ie the array class).

 Value containers are compositions that store copies of the objects that they are holding (and thus ar
 responsible for creating and destroying those copies

 Reference containers are aggregations that store pointers or references to other objects (and thus are not
 responsible for creation or destruction of those objects).
*/

#include "IntArray.h"
#include <iostream>

int main() {
    // Declare an array with 10 elements
    IntArray array{ 10 };

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insert_before(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insert_at_end(30);
    array.insert_at_beginning(40);

    // Print out all the numbers
    for (int i{ 0 }; i < array.size(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';
}