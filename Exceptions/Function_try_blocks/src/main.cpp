/*
Function try blocks are designed to allow you to establish an exception handler around the
body of an entire function, rather than around a block of code.

Unlike normal catch blocks, which allow you to either resolve an exception, throw a new exception,
or rethrow an existing exception, with function-level try blocks, you must throw or rethrow an
exception. If you do not explicitly throw a new exception, or rethrow the current exception
(using the throw keyword by itself), the exception will be implicitly rethrown up the stack.

Although function level try blocks can be used with non-member functions as well, they
typically aren’t because there’s rarely a case where this would be needed. They are almost
exclusively used with constructors.

Function try is useful primarily for either logging failures before passing the exception up the
stack, or for changing the type of exception thrown.
*/
#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{ x }
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	B(int x) try : A{ x } // note addition of try keyword here
	{
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
		// Exceptions from member initializer list or constructor body are caught here

		std::cerr << "Exception caught\n";

		// If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
	}
};

int main()
{
	try
	{
		B b{ 0 };
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}