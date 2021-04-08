/*
The () operator lets you vary the type and number of parameters it takes. The parenthesis operator
must be implemented as a member function.

OPerator() is also commonly overloaded to implement functors (or function object), which are classes
that operate like functions. Functors can store data in member variables since they are classes.

Operator() is sometimes overloaded with two parameters to index multidimensional arrays, or to retrieve
a subset of a one dimensional array (with the two parameters defining the subset to return).
Anything else is probably better written as a member function with a more descriptive name.
Operator() is also often overloaded to create functors.
*/

#include <iostream>
#include <cassert> // for assert()

class Matrix {
private:
	double m_matrix[4][4];
public:
	double& operator() (int row, int col) {
		assert(row >= 0 && row < 4 && col >= 0 && col < 4);
		return m_matrix[row][col];
	}
	const double& operator() (int row, int col) const {
		assert(row >= 0 && row < 4 && col >= 0 && col < 4);
		return m_matrix[row][col];
	}
	void operator() () {
		// Reset all elements to 0.0.
		for (auto& row : m_matrix) {
			for (auto& elem : row) {
				elem = 0.0;
			}
		}
	}
};

void matrix() {
	Matrix A;
	A(1, 2) = 4.5;
	std::cout << A(1, 2) << std::endl; // 4.5
	A();
	std::cout << A(1, 2) << std::endl; // 0.0
}

class Accumulator {
private:
	int m_counter{};
public:
	int operator() (int increment) { return (m_counter += increment); }
};

void functor() {
	Accumulator acc;
	std::cout << acc(10) << std::endl; // Returns 10.
	std::cout << acc(20) << std::endl; // Returns 30.
}

class Mystring {
private:
	std::string m_string;
public:
	Mystring(const std::string& string = {})
		:m_string{ string }
	{
	}

	std::string operator() (int start, int length) {
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) &&
			   "Mystring::operator(int, int): Substring is out of range");
		
		std::string substring{};
		for (int index{ start }; index < start + length; index++) {
			substring += m_string[static_cast<std::string::size_type>(index)];
		}
		return substring;
	}
};

void Q1() {
	// Write a class that holds a string. Overload operator() to return the substring that
	// starts at the index of the first parameter. The length of the substring should be
	// defined by the second parameter.
	Mystring string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters
}

int main() {
	matrix();
	functor();
	Q1();
}