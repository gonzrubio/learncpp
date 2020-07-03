#include <iostream>

using namespace std;

int pow(int base, int exponent)
{
    int kk = 0 ;
    int total = 1 ;
    while(kk < exponent)
    {
        total *= base ;
        ++kk ;
    }
    return total ;
}

int sumFirstN(int N)
{
    // Calculate sum of first N positive integers.
    int total = 0 ; // Acummulator.
    int ii = 1 ;
    while (ii <= N)
    {
        total += ii ;
        ++ii ;
    }

    return total ;
}

int main()
{

    /*
    Print numbers from 1 to 50 with every 10 on each line.
    */

    // Debug.
    int count = 1 ;
    int lastNumber = 50 ;

    while (count <= lastNumber)
    {
        if (count < 10)
            cout << "0" << count << " " ;
        else
            cout << count << " " ;

        if (count % 10 == 0)
            cout << endl ;
        ++count ;
    }

    // Nested While loop

    int outer =  1 ;
    int nrow = 5 ;
    while (outer <= nrow)
    {

        int inner = 1 ;
        while (inner <= outer)
        {
            // Note the ++ after the variable. This prints inner first and then increments its value.
            cout << inner++ << " " ;
        }
        cout << endl ;
        // Here we add first since we are not printing out anything to the console.
        ++outer ;
    }

    char mychar = 'a';
    while (mychar <= 'z')
    {
        cout << mychar  << " " << static_cast<int>(mychar) << "\n";
        ++mychar;
    }

    int out = 1 ; // Outer loop counter.
    int maxRows = 5 ; // Number of rows.

    while (out <= maxRows)
    {
        // Row elements appear in descending order so start from top and loop down to 1.
        int in = maxRows ;

        while(1 <= in)
        {
            if (in <= out)
                cout << in << " " ;
            else
                cout << "  " ;
            --in ;
        }
        // After a row has been printed, move to the next one.
        cout << endl ;
        ++out ;

    }

    cout << "Enter a base followed by a power." << endl ;
    int a, b ;
    cin >> a ;
    cin >> b ;

    cout << a << " to the power of " << b << " is " << pow(a,b) << endl ;

    cout << endl ;

    for (int ii = 10 ; 1 < ii ; ii -= 2)
    {
        cout << ii << " " ;
    }

    cout << endl << sumFirstN(3) << endl << endl ;

    int start = 0 ;
    int last = 10 ;
    for (int ii = start, jj = last ; ii <= last ; ++ii, --jj)
    {
        cout << ii << " " << jj << endl ;
    }

    return 0;
}
