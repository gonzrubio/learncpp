#include <iostream>
#include <string>

using namespace std;

int recFactorial(long int n)
{
    if (n == 0 || n == 1) return 1 ;  // Base case.
    else return n*recFactorial(n-1) ; // Recursive case.
}

// Wrapper
int factorial(long int n)
{
    return recFactorial(n) ;
}

void sPermute(string soFar, string rest)
{
    // Base case
    if (rest == "")
        cout << soFar << endl ;
    else
    {
        for (int ii = 0 ; ii < rest.length() ; ii++)
        {
            string next = soFar + rest[ii] ;
            string remaining = rest.substr(0,ii) + rest.substr(ii+1) ;
            sPermute(next, remaining) ;
        }
    }

}

int main()
{
    long int number{ 13 } ;
    cout << number << "! = " << recFactorial(number) << endl ;

    string letters{ "abcde" } ;
    cout << "The permuataions of " << letters << " are: " << endl ;
    sPermute("",letters) ;

    return 0;
}
