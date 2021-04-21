/*
One of the best things about classes is that they contain destructors that automatically get
executed when an object of the class goes out of scope. So if you allocate (or acquire) memory
in your constructor, you can deallocate it in your destructor, and be guaranteed that the memory
will be deallocated when the class object is destroyed (regardless of whether it goes out of
scope, gets explicitly deleted, etc…).

As long as Auto_ptr1 is defined as a local variable (with automatic duration, hence the “Auto”
part of the class name), the Resource will be guaranteed to be destroyed at the end of the block
it is declared in, regardless of how the function terminates (even if it terminates early).

Such a class is called a smart pointer. A Smart pointer is a composition class that is designed
to manage dynamically allocated memory and ensure that memory gets deleted when the smart pointer
object goes out of scope.

Move semantics means the class will transfer ownership of the object rather than making a copy.
*/

#include <iostream>

template<class T>
class Auto_ptr1 {
	T* m_ptr;
public:
	// Pass in a pointer to "own" via the constructor
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	// The destructor will make sure it gets deallocated
	~Auto_ptr1()
	{
		delete m_ptr;
	}

	// Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
};

// A sample class to prove the above works
class Resource {
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	void sayHi() { std::cout << "Hi!\n"; }
};

void someFunction() {
	Auto_ptr1<Resource> ptr(new Resource()); // ptr now owns the Resource

	int x;
	std::cout << "Enter an integer: ";
	std::cin >> x;

	if (x == 0)
		return; // the function returns early

	// do stuff with ptr here
	ptr->sayHi();
}

void example1() {
	Auto_ptr1<Resource> res(new Resource()); // Note the allocation of memory here
		// ... but no explicit delete needed
	// Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
} // res goes out of scope here, and destroys the allocated Resource for us

template<class T>
class Auto_ptr2
{
	T* m_ptr;
public:
	Auto_ptr2(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

int main() {
	example1();
	someFunction();
}