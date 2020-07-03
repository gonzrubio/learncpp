#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string s = "Gonzalo" ; // string s ; assumes empty string.
    string s ;
    cout << "Whats your full name in lower case letters?" << endl ;
    getline(cin,s) ;

    for (int i = 0 ; i < s.length() ; i ++)
        s[i] = toupper(s[i]) ;
        // cout << s[i] << endl ;

    cout << "Your nombre in upper case letters is " << s << "." << endl ;

    return 0;
}
