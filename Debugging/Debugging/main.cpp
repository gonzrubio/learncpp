#include <iostream>
using namespace std ;

int add(int x, int y)
{
	return x + y;
}

void printResult(int z)
{
	cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	// return --x;
	return x ;
}

int main()
{
	int x{ getUserInput() };
	int y{ getUserInput() };
    cerr << "x = " << x << " y = " << y << endl ;

	int z { add(x, y) };
    cerr << "z = x + y = " << z << endl ;

	printResult(z);

	return 0;
}
