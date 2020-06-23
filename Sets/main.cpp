#include <iostream>
#include <set>
#include <random>
#include <map>

using namespace std;

void testRandom()
{
    set<int> seen ;
    while (true)
    {
        int num = randomInteger(1,100) ;
        if (seen.contains(num)) break ;
        seen.add(num) ;
    }

    set<int>::iterator itr = seen.iterator() ;
    while (itr.hasNext())
        cout << itr.next() << endl ;

}

int main()
{
    randomize() ;
    testRandom() ;
    return 0;
}
