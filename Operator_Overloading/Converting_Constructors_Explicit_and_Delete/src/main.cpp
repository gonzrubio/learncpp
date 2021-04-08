/*
By default, C++ will treat any constructor as an implicit conversion operator.
This implicit conversion works for all kinds of initialization (direct, uniform, and copy).
Constructors eligible to be used for implicit conversions are called converting
constructors (or conversion constructors).

Implicit conversions are avioded by making constructors (and conversion functions) 
explicit via the explicit keyword. Making a constructor explicit only prevents
implicit conversions. Explicit conversions (via casting) are still allowed.

Consider making your constructors and user-defined conversion member functions explicit
to prevent implicit conversion errors.

When a function has been deleted, any use of that function is considered a compile error.
Note that the copy constructor and overloaded operators may also be deleted in order to
prevent those functions from being used.
*/

#include <iostream>

class MyString {
private:
	std::string m_string;
public:
	MyString(char) = delete; // any use of this constructor is an error

	// explicit keyword makes this constructor ineligible for implicit conversions
	explicit MyString(int x) {
		// allocate string of size x
		m_string.resize(x);
	}

	MyString(const char* string) {
		// allocate string to hold string value
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);

};

std::ostream& operator<<(std::ostream& out, const MyString& s) {
	out << s.m_string;
	return out;
}

void printString(const MyString& s) {
	std::cout << s;
}

int main() {

}