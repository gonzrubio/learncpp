/*
One of the biggest problems that new programmers run into when using exceptions is the
issue of cleaning up resources when an exception occurs.

std::unique_ptr is a template class that holds a pointer, and deallocates it when it goes out of scope.

Unlike constructors, where throwing exceptions can be a useful way to indicate that object creation did
not succeed, exceptions should never be thrown in destructors.

The problem occurs when an exception is thrown from a destructor during the stack unwinding process.
If that happens, the compiler is put in a situation where it doesn’t know whether to continue the stack
unwinding process or handle the new exception. The end result is that your program will be terminated immediately.

Exceptions do come with a small performance price to pay. They increase the size of your executable,
and they may also cause it to run slower due to the additional checking that has to be performed.
However, the main performance penalty for exceptions happens when an exception is actually thrown.
In this case, the stack must be unwound and an appropriate exception handler found, which is a
relatively expensive operation.

Exception handling is best used when all of the following are true:

	- The error being handled is likely to occur only infrequently.
	- The error is serious and execution could not continue otherwise.
	- The error cannot be handled at the place where it occurs.
	- There isn’t a good alternative way to return an error code back to the caller.
*/

#include <iostream>

int main() {

}