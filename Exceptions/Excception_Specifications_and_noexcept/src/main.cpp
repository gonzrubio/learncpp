/*
In C++, all functions are classified as either non-throwing (do not throw exceptions) or
potentially throwing (may throw an exception).

The noexcept specifier defines a function as non-throwing. To define a function as non-throwing,
we can use the noexcept specifier in the function declaration, placed to the right of the function
parameter list. 

Note that noexcept doesn’t actually prevent the function from throwing exceptions or calling other
functions that are potentially throwing. Rather, when an exception is thrown, if an exception exits
a noexcept function, std::terminate will be called. And note that if std::terminate is called from
inside a noexcept function, stack unwinding may or may not occur (depending on implementation and
optimizations), which means your objects may or may not be destructed properly prior to termination.

Much like functions that differ only in their return values can not be overloaded, functions differing
only in their exception specification can not be overloaded.

The noexcept operator can be used inside functions. It takes an expression as an argument, and returns
true or false if the compiler thinks it will throw an exception or not. The noexcept operator is
checked statically at compile-time, and doesn’t actually evaluate the input expression.

Use the noexcept specifier in specific cases where you want to express a no-fail or no-throw guarantee.
*/

#include <iostream>

int main() {
	void foo() { throw - 1; }
	void boo() {};
	void goo() noexcept {};
	struct S {};

	constexpr bool b1{ noexcept(5 + 3) }; // true; ints are non-throwing
	constexpr bool b2{ noexcept(foo()) }; // false; foo() throws an exception
	constexpr bool b3{ noexcept(boo()) }; // false; boo() is implicitly noexcept(false)
	constexpr bool b4{ noexcept(goo()) }; // true; goo() is explicitly noexcept(true)
	constexpr bool b5{ noexcept(S{}) };   // true; a struct's default constructor is noexcept by default
}