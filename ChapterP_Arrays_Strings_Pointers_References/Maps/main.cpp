#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int maxWords = 100 ;

void countOcurrences(string &arr)
{
    Map<string, int> ocurrences ;
    for (int ii = 0 ; ii < sizeof(arr) / sizeof(arr[0]) ; ii++)
        cout << arr[ii] ;
    /*{
        map<string, int>::iterator it ;
        it = ocurrences.find(arr[ii]) ;
        if (it != ocurrences.end() )
            ocurrences(arr[ii]) += 1 ;
        else
            ocurrences(arr[ii]) = 1 ;
    }
    cout << ocurrences.size() ;
    */
}

int main()
{

    string greet[14] = {"hello","hello","hello","hello","hola","hola","hola","hola","alo","alo","nihao","bonjour","bonjour","bonjour"} ;

    countOcurrences(greet) ; // Make map conatining the ocurrences and their counts.


    return 0;
}
