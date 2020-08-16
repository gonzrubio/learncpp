#include <iostream>
#include <string>

using namespace std ;

int RecSubsets(string soFar,string rest,int &total)
{
    // Base case
    if (rest == "")
    {
        printf("'%s'\n",soFar.c_str()) ;
        total += 1 ;
    }
    else
    {
        // Add to subset, remove from rest, recur.
        RecSubsets(soFar + rest[0],rest.substr(1),total) ;
        // Dont add to subset, remove from rest, recur.
        RecSubsets(soFar,rest.substr(1),total) ;
    }

    return total ;
}

void PossibleSubsets(string s)
{
    int subsets{ 0 } ;
    subsets = RecSubsets("",s,subsets) ;
    printf("There are %d possible subsets in %s", subsets, s.c_str()) ;
}

int main()
{
    string letters{"abcd"} ;
    PossibleSubsets(letters) ;

    return 0;
}
