/*
Creating template classes works pretty much identically to creating template functions.
Each templated member function defined outside the class declaration needs its own template declaration.
It also needs to know the full definition of the class (along with its methods) at compile time. It cannot
just use the class definition and delay linking until later.

Template classes are ideal for implementing container classes, because it is highly desirable to have
containers work across a wide variety of data types, and templates allow you to do so without duplicating code.

With non-template classes, the common procedure is to put the class definition in a header file, and the member
function definitions in a similarly named code file. In this way, the source for the class is compiled as a
separate project file. However, with templates, this does not work. In order for the compiler to use a template,
it must see both the template definition (not just a declaration) and the template type used to instantiate the template.
*/

#include "Array.h"
#include <iostream>

int main() {
	Array<int> intArray(12);
	Array<double> doubleArray(12);

	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';
}