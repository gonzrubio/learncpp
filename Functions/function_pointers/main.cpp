#include <iostream>
#include <functional>

/*
    Recall...
    Pointers are variables that hold the adress of another variable or nullptr.

    Function pointers: Hold the adress of a function. They point to funcitons.
    Like variables, functions live at an assigned adress in memory.

    Note0: The type and (parameters and return type) of the function pointer must match
    the type of the function.

    Note1: Unlike fundamental types, fucntions are implicitly converted to function pointers
    so there is no need to ude the adress-of operator (&). However, it will not implicitly convert
    function pointers to void pointers, or vice-versa.

    Note2: Implicit dereference method looks like a normal function call. That is because
    normal funciton names are pointers to functions!

    Note3: Functions can be used as arguments to other functions, these are called callback functions.
    * See Selection sort example.

    Conclusion: Function pointers are useful when you want to store functions in an array (or other structure)
    or when you need to pass a function to another function.
*/

int foo()
{
    // Identifier foo is the functions name.
    // foo is stored at some location in memory, say location abcd.
    // The type of the function is: returns an integer and takes no parameters.
    return 5 ;
}

int goo()
{
    return 6 ;
}

double hoo(int x)
{
    //int temp{ 3*x } ;
    //return temp ;
    return 69.69 ;
}

void intro()
{
    foo() ; // Jump to adress abcd.
    std::cout << "foo() returns: " << foo() << " and is located at memory adress: " << reinterpret_cast<void*>(foo) <<'\n' ;

    int (*fcnPtr)(){ foo } ; // Initialize function pointer with a function (points to function foo).
    std::cout << "fncPtr is a function pointer that takes no arguments and returns an int: " << reinterpret_cast<void*>(fcnPtr) <<'\n' ;

    // Can also make it a constant pointer.
    // Both pointers now pointing at the same function.
    int (*const fcnPtr0)(){ foo } ;

    std::cout << "goo() returns: " << goo() << " and is located at memory adress: " << reinterpret_cast<void*>(goo) <<'\n' ;
    fcnPtr = goo ; //fcnPtr now points at function goo.
    std::cout << "fcnPtr is now assigned to goo and points to memory adress: " << reinterpret_cast<void*>(fcnPtr) << '\n' ;

    // Parameters and return types must of the function pointer must match the type of the function.
    double (*fcnPtr69)(int){ hoo } ;

    // Can use function pointers to call a function (implicit or explicit dereference).
    std::cout << "hoo(5) = " << (*fcnPtr69)(5) ;
}

// Type alias for a function pointer that takes two integer parameters and returns an int.
// using arithmeticFcn = std::function<int(int,int)>

int add(int a, int b)
{
    return a+b ;
}

int subtract(int a, int b)
{
    return a-b ;
}

int multiply(int a, int b)
{
    return a*b ;
}

int divide(int a, int b)
{
    return a/b ;
}

int getInteger()
{
    int a ;
    std::cout << "Enter an integer: " ;
    std::cin >> a ;
    return a ;
}

char getOperator()
{
    char op ;
    while (op!='+' && op!='-' && op!='*' && op!='/')
    {
        std::cout << "Enter an operator ('+', '-', '*', '/'): " ;
        std::cin >> op ;
    }
    return op ;
}

//arithmeticFcn getArithmeticFunction(char op)
std::function<int(int, int)> getArithmeticFunction(char op)
{
    // This function returns a fucntion pointer based on the character input.
	switch (op)
	{
	default: // default will be to add
	case '+': return add ;
	case '-': return subtract ;
	case '*': return multiply ;
	case '/': return divide ;
	}
}

void quiz()
{
    int a{ getInteger() } ;
    char op{ getOperator() } ;
    int b{ getInteger() } ;
    std::function<int(int,int)> fcn{ getArithmeticFunction(op) } ;
    std::cout << a << " " << op << " " << b << " = " << fcn(a,b) ;

}

int main()
{
    // intro() ;
    quiz() ;

    return 0;
}
