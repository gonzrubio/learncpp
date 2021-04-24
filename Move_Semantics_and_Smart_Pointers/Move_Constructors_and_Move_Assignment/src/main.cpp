/*
Copy constructors are used to initialize a class by making a copy of an object of the same class.
Copy assignment is used to copy one class to another existing class. By default, C++ will provide
a copy constructor and copy assignment operator if one is not explicitly provided.
These compiler-provided functions do shallow copies, which may cause problems for classes that
allocate dynamic memory. So classes that deal with dynamic memory should override these functions
to do deep copies.

Whereas the goal of the copy constructor and copy assignment is to make a copy of one object to
another, the goal of the move constructor and move assignment is to move ownership of the resources
from one object to another (which is typically much less expensive than making a copy).

Defining a move constructor and move assignment work analogously to their copy counterparts.
However, whereas the copy flavors of these functions take a const l-value reference parameter,
the move flavors of these functions use non-const r-value reference parameters.

The move constructor and move assignment operator are simple. Instead of deep copying the source
object (a) into the implicit object, we simply move (steal) the source object’s resources.
This involves shallow copying the source pointer into the implicit object, then setting the source
pointer to null.


*/


#include <iostream>


template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};


class Resource {
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};


Auto_ptr4<Resource> generateResource() {
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}


void example_1() {
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment
}


int main() {
	example_1();
}