#include <iostream>
#include <vector>

/*
    Recursion is a good chice when:
    - The recursive code is much simpler to implement.
    - The recursion depth can be limitied.
    - The iterative version of the algorithm requires managing a stack of data.
    - This isnt a performance-critical section of the code.

    Memoization: Cache the results of previous recursive calls.
*/

void countDown(int n)
{
    std::cout << "push " << n << '\n' ;

    if (n > 1) // termination condition
        countDown(n-1);

    std::cout << "pop " << n << '\n' ;
}

int fibonacci(int n)
{
    // Note: This recursion algorithm is not very efficient since each
    // non-base case recults in two more recursive calls, this grows exponentially.

    // Base case.
    if (n == 0) return 0 ;
    else if (n == 1) return 1 ;
    // Recursive case.
    else return (fibonacci(n-1)+fibonacci(n-2)) ;
}

int fibonacciCache(int n)
{
    // Initialize with base cases.
    static std::vector<int> fibNums{0,1} ;

    // Use cache'd result if we have seen this 'n'.
    if (n < fibNums.size())
        return fibNums[n] ;
    else
    {
        // Otherwise calculate it and add it to vector.
        fibNums.push_back(fibonacciCache(n-2) + fibonacciCache(n-1)) ;
        return fibNums[n] ;
    }
}

void printFib(int start, int stop, int (*fcnPtr)(int))
{
    for (int kk{0} ; kk < 13 ; kk++)
        std::cout << fcnPtr(kk) << " " ;
    std::cout << '\n' ;
}

int sumNumbers(int x)
{
    // Returns the sum of each individual number.

    // Base case.
    if (x < 10) return x ;
    // Recursive case.
    // Take the integer part and sum the remainder,
    // when dividing by 10 (base 10).
    else return (sumNumbers(x / 10) + x % 10) ;
}

void printBinary(int x)
{
    // Termination case
	if (x == 0)
		return;

	// Recurse to the next bit
	printBinary(x / 2);

	// Print out the remainders (in reverse order)
	std::cout << x % 2;
}

int main()
{
    countDown(5) ;
    printFib(0,13,fibonacci) ;
    printFib(0,13,fibonacciCache) ;
    std::cout << sumNumbers(93427) << '\n' ;
    printBinary(93427) ;

    return 0;
}
