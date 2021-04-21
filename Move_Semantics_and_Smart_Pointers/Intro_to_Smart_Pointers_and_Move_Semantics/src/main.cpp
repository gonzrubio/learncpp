/*
One of the best things about classes is that they contain destructors that automatically get
executed when an object of the class goes out of scope. So if you allocate (or acquire) memory
in your constructor, you can deallocate it in your destructor, and be guaranteed that the memory
will be deallocated when the class object is destroyed (regardless of whether it goes out of
scope, gets explicitly deleted, etc…).
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
};

void example1() {
	Auto_ptr1<Resource> res(new Resource()); // Note the allocation of memory here
		// ... but no explicit delete needed
	// Also note that the Resource in angled braces doesn't need a * symbol, since that's supplied by the template
} // res goes out of scope here, and destroys the allocated Resource for us

int main() {
	example1();
}