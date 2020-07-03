#include <iostream>
#include <vector>

void printStack(const std::vector<int> &stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

void staccBehaviour()
{
	std::vector<int> stack;

	printStack(stack);

	stack.push_back(5); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() back pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.reserve(5); // Set the capacity to (at least) 5

	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n';

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);
}

int main()
{
    staccBehaviour() ;

    //  Vectors may allocate extra capacity than needed.
    // This is becaus eresizing is expensive so this provides
    // a way of minimizing the number of times the vector gets resized.
    // If, when, and how much additional capacity of left up to the compiler implementer.

	std::vector<int> v = { 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v.push_back(5); // add another element
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';
    return 0;
}
