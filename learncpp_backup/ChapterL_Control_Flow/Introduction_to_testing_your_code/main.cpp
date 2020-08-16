#include <iostream>

using namespace std;

void compare(int a, int b)
{
    if (a>b)
        cout << "x is biger than y." << endl ;
    else if (b>a)
        cout << "y is bigger than x." << endl ;
    else
        cout << "x is equal to y." << endl ;
}

void testCompare()
{
    // To test compare need to go through all cases of the if statements.
    cout << "Entering testCompare()" << endl ;
    cout << "x = y = 0." << endl ;
    compare(0,0) ;
    cout << "x = 1, y = 0." << endl ;
    compare(1,0) ;
    cout << "x = 0, y = 1." << endl ;
    compare(0,1) ;
}

int foo(int x, int y)
{
    bool z = y ;
    if (x > y)
        z = x ;

    return z ;
}

void testFoo()
{
    cout << "Entering testFoo()"  << endl ;
    cout << "x = 1 and y = 0 so z = " << foo(1,0) << endl ; // These parameters give 100% statement coverage.
    cout << "x = 0 and y = 1 so z = " << foo(0,1) << endl ; // Now we have also excersiced the negative case of the if statement.
}

void spam(int num)
{
    for (int ii = 0 ; ii < num ; ii++)
    {
        cout << "SPAM! " ;
    }
    cout << endl ;

}

void testSpam()
{
    for (int jj = 0 ; jj < 3 ; jj++)
    {
        cout << "Testing spam with jj = " << jj << "." << endl ;
        spam(jj) ;
    }

}


int main()
{
    // Testing tip #1: Write small functions (units), compile often and test.
    testCompare() ;

    // Testing tip #2: Aim for 100% statement converage.
    // The percentage of excersiced statements in the code by the testing routines.

    // Testig tip #3: Aim for 100% branch coverage.
    // The percentage of executed branches.
    testFoo() ;

    // Testing tip #4: Aim for 100% loop coverage.
    // Test for 0,1,2 iterations.
    testSpam() ;

    // Testing tip #5: Ensure you are testing different categories of input.
    // For integers: 0, positive and negative.
    // For strings: Empty string, valid string, strings with white space, all white space.


    return 0;
}
