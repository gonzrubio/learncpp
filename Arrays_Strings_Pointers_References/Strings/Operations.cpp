#include <iostream>
#include <string>

using namespace std ;

int CountOcurrences(char ch, string s)
{
    /*
        Count character occurences in a string.
    */

    int count = 0 ;
    for (int i = 0 ; i < s.length() ; i++)
        if (s[i] == ch)
            count += 1 ;
    return count ;
}

string RemoveOcurrences(char ch, string s)
{
    /*
        Return new string where the specified character is removed.
    */

    string result ;
    for (int i = 0 ; i < s.length() ; i++)
        if (s[i] != ch)
            result += s[i] ; // Can extend empty string by concatenating elements.
    return result ;
}


int main()
{

    string s ; // Initialize empty string.
    string t = "hello" ;

    s = t ; // Make copy of t. Do not point to same memory.

    cout << s << endl ;
    cout << t << endl ;
    bool compppp = s == t ;
    cout << compppp << endl ;

    t[0] = 'j' ; // Need '' rather than "" when replacing character.

    cout << t << endl ;

    s += " " ; // Concatenate space character.

    cout << s << endl ;

    if (s != t)
        t += t ; // Concatenate itself.

    cout << t << endl ;

    cout << s.length() << endl ;

    int ls = s.length() ;

    cout << s+s << ls << endl ;

    string ss = "cacahuate cocacola chichimeca" ;
    cout << CountOcurrences('c', ss) << endl ;
    string sswithout = RemoveOcurrences('c', ss) ; // Doesnt change string in place.
    cout << sswithout << endl ;

    //RemoveOcurrencesInPlace(char ch, string ss)
    //cout << ss << endl ; // Changes string in place.

    return 0 ;

}

/*
void RemoveOcurrencesInPlace(char ch, string &s)
{
    /*
        Return same string where the specified character is removed.
    */

    /*
    string result ;
    for (int i = 0 ; i < s.length() ; i++)
        if (s[i] != ch)
            result += s[i] ; // Can extend empty string by concatenating elements.
    return result ;
}
*/
