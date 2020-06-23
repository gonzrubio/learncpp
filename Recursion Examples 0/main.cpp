#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int powerLoop(int base, int exp)
{
    int result = 1 ;
    for (int ii = 0 ; ii < exp; ii++)
        result *= base ;
    return result ;
}

int powerRec(int base, int exp)
{
    // Base case
    if (exp == 0) return 1 ;
    // Recursive case
    else
        return base*powerRec(base,exp-1) ;
}

int powerRecEff(int base, int exp)
{
    // Base case
    if (exp == 0) return 1 ;
    // Recursive case
    else
    {
        int half = powerRecEff(base, exp / 2) ;
        if (exp % 2 == 0) return half * half ;
        else return base * half * half ;
    }
}

void testPower(int a, int b)
{
    cout << "Iterative formulaiton: " << a << "^" << b << " = " << powerLoop(a,b) << endl ;
    cout << "Recursive formaulation: " << a << "^" << b << " = " << powerRec(a,b) << endl ;
    cout << "Efficient recursive formaulation: " << a << "^" << b << " = " << powerRecEff(a,b) << endl ;
}

bool isPalindrome(string s)
{
    if (0 <= s.length()) return true ;
    return (s[0] == s[s.length()-1] && isPalindrome(s.substr(1,s.length()-2))) ;
}

string removeSpaces(string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end()) ;
  return input ;
}

void testPalindrome(string s)
{
    string s1{ removeSpaces(s) };
    cout << "Testing isPalindrome() ..." << endl ;
    if (isPalindrome(s1))
        cout << s << " is a palindrome." << endl ;
    else
        cout << s << " is not a palindrome." << endl ;
}

int choose(int n, int k)
{
    /*
    Whenever we choose k elements out of n, there are two cases:
    1) The ones that include n.
    2) The ones that dont.
    Since these are mutually exclusive, then the total amount is their sum.

    If we fix one choice (n) then we have to:
    A) choose k-1 to group with the nth ememebr out of n-1 population.
        - This will eventually go down to k=0 since 0<=k<=n.
    B) Chose k (option without n) out of n-1.
        - This will eventually go down to k=n, cant be less since k<=n.

    Eventually we will:

    */
    if (k == 0|| k == n) return 1 ;
    else return ( choose(n-1,k) + choose(n-1,k-1) ) ;
}

void testChoose(int n, int k)
{
    cout << "There are " << choose(n,k) << " ways to group " << k << " people out of " << n << " people." << endl ;
}

int main()
{
    testPower(6,9) ;
    testPalindrome("was it a car or a cat i saw") ;
    testChoose(13,2) ;

    return 0;
}
