/*
An exception class is just a normal class that is designed specifically to be thrown as an exception.
Exception handlers will not only match classes of a specific type, they’ll also match classes derived
from that specific type as well.

Rule: Handlers for derived exception classes should be listed before those for base classes.

std::exception is a small interface class designed to serve as a base class to any exception
thrown by the C++ standard library.
*/

#include <cstddef> // for std::size_t
#include <iostream>
#include <exception> // for std::exception
#include <limits>
#include <string> // for this example

class ArrayException {
private:
    std::string m_error;
public:
    ArrayException(std::string error) : m_error{ error } {}
    const char* getError() const { return m_error.c_str(); }
};

class IntArray {
private:
	int m_data[3]; // assume array is length 3 for simplicity
public:
	IntArray() {}
	int getLength() const { return 3; }
	int& operator[](const int index) {
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");
		return m_data[index];
	}
};

int main() {
	IntArray array;
	try {
		int value{ array[5] };
	}
	catch (const ArrayException& exception) {
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
	try
	{
		// Your code using standard library goes here
		// We'll trigger one of these exceptions intentionally for the sake of the example
		std::string s;
		s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
	}
	// This handler will catch std::exception and all the derived exceptions too
	catch (const std::exception& exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}
}