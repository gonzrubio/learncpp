/*
Operator overloading is a variant of function overloading that lets you overload operators
for your classes. When operators are overloaded, the intent of the operators should be kept
as close to the original intent of the operators as possible. If the meaning of an operator
when applied to a custom class is not clear and intuitive, use a named function instead.

Operators can be overloaded as a normal function, a friend function, or a member function.
	- If you’re overloading assignment (=), subscript ([]), function call (()), or member
	selection (->), do so as a member function.
	- If you’re overloading a unary operator, do so as a member function.
	- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=),
	do so as a member function if you can.
	- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+),
	do so as a normal function or friend function.

Typecasts can be overloaded to provide conversion functions, which can be used to explicitly
or implicitly convert your class into another type.

A copy constructor is a special type of constructor used to initialize an object from another
object of the same type. Copy constructors are used for direct/uniform initialization from an
object of the same type, copy initialization, and when passing or returning a parameter by value.

If you do not supply a copy constructor, the compiler will create one for you. Compiler-provide
copy constructors will use memberwise initialization, meaning each member of the copy is
initialized from the original member. The copy constructor may be elided for optimization purposes,
even if it has side-effects, so do not rely on your copy constructor actually executing.

Constructors are considered converting constructors by default, meaning that the compiler will use
them to implicitly convert objects of other types into objects of your class. You can avoid this by
using the explicit keyword in front of your constructor. You can also delete functions within your
class, including the copy constructor and overloaded assignment operator if desired. This will cause
a compiler error if a deleted function would be called.

The assignment operator can be overloaded to allow assignment to your class. If you do not provid
an overloaded assignment operator, the compiler will create one for you. Overloaded assignment
operators should always include a self-assignment check.
	- If a new object has to be created before the copying can occur, the copy constructor is
	used (note: this includes passing or returning objects by value).
	- If a new object does not have to be created before the copying can occur, the assignment
	operator is used.

By default, the copy constructor and assignment operators provided by the compiler do a memberwise
initialization or assignment, which is a shallow copy. If your class dynamically allocates memory,
this will likely lead to problems, as multiple objects will end up pointing to the same allocated
memory. In this case, you’ll need to explicitly define these in order to do a deep copy.
Even better, avoid doing your own memory management if you can and use classes from
the standard library.
*/

#include "IntArray.h"
#include "Average.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Average &average) {
	out << static_cast<double>(average.m_sum) / average.m_len;
	return out;
}

void Q2() {
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';
}

class IntArray
{
private:
	int m_length{ 0 };
	int* m_array{ nullptr };

public:
	IntArray(int length) :
		m_length{ length }
	{
		assert(length > 0 && "IntArray length should be a positive integer");

		m_array = new int[m_length] {};
	}

	// Copy constructor that does a deep copy
	IntArray(const IntArray& array) :
		m_length{ array.m_length }
	{
		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
	}

	// If you're getting crazy values here you probably forgot to do a deep copy in your copy constructor
	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
	{
		for (int count{ 0 }; count < array.m_length; ++count)
		{
			out << array.m_array[count] << ' ';
		}
		return out;
	}

	int& operator[] (const int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		return m_array[index];
	}

	// Assignment operator that does a deep copy
	IntArray& operator= (const IntArray& array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_length = array.m_length;

		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}

};

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {
	Q2();
	IntArray a{ fillArray() };

	// If you're getting crazy values here you probably forgot to do a deep copy in your copy constructor
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	// If you're getting crazy values here you probably forgot to do a deep copy in your assignment operator
	// or you forgot your self-assignment check
	std::cout << b << '\n';
}