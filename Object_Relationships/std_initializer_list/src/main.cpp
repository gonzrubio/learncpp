/*
When a compiler sees an initializer list, it automatically converts it into an object of type std::initializer_list.
Therefore, if we create a constructor that takes a std::initializer_list parameter, we can create objects
using the initializer list as an input.
If you provide list construction, it’s a good idea to provide list assignment as well.
*/

#include "IntArray.h"
#include <iostream>

int main() {
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';
}