/*
The protected ccess specifier allows the class the member belongs to, friends and derived classes to access the member.
However, protected memebers are not accessible from outside the class.

There are three different ways for classes to inherit from other classes: public, protected, and private.
Default is private inheritance.

In public inheritance, inherited public members stay public, inherited protected members stay protected,
and inherited private members stay inaccessible.

Rule: Use public inheritance unless you have a specific reason to do otherwise.
*/

#include <iostream>

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class D2 : private Base // note: private inheritance
{
	// Private inheritance means:
	// Public inherited members become private
	// Protected inherited members become private
	// Private inherited members stay inaccessible
public:
	int m_public2;
protected:
	int m_protected2;
private:
	int m_private2;
};

class D3 : public D2
{
	// Public inheritance means:
	// Public inherited members stay public
	// Protected inherited members stay protected
	// Private inherited members stay inaccessible
public:
	int m_public3;
protected:
	int m_protected3;
private:
	int m_private3;
};

int main() {

}