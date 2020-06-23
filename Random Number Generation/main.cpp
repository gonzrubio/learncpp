#include <iostream>
#include <stdio.h>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>
#include <random> // for std::mt19937.
#include "random.hpp"

using namespace std;
using Random = effolkronium::random_static;

// Create a globla random number generator
/*namespace MyRandom
{
    // Initialize our mersenne twister with a random seed based on the clock (once at system startup)
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) } ;
}

int getRandomInt(int minimum, int maximum)
{
    std::uniform_int_distribution die{min, max} ; // we can create a distribution in any function that needs it
    return die(MyRandom::mersenne) ;     // and then generate a random number from our global generator
}*/

unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed{ 5323 };

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // hard for someone to casually predict what the next number is
    // going to be from the previous one.
    seed = 8253729 * seed + 2396403;

    // Take the seed and return a value between 0 and 32767
    return seed % 32768;
}

void printRandom(int iter, int col, bool method, int seed)
{
    srand(seed) ;

    if (!method)
    {
        cout << "Proprietary PRNG: " << endl ;
        for (int kk = 1 ; kk <= iter; kk++)
        {
            cout << PRNG() << '\t' ;
            if (kk % col == 0)
                cout << endl ;
        }
    }
    else
    {
        cout << "Built-in PRNG: " << endl ;
        for (int kk = 1 ; kk <= iter; kk++)
        {
            cout << rand() << '\t' ;
            if (kk % col == 0)
                cout << endl ;
        }
    }
    cout << endl ;
}

void printRandomClock(int iter, int col)
{
    // Set initial value to system clock.
    srand(static_cast<unsigned int>(time(nullptr))) ;

    cout << "System clock method: " << endl ;
    for (int ii = 1 ; ii <= iter ; ii++)
    {
        cout << rand() << '\t' ;
        if (ii % col == 0)
            cout << endl ;
    }
}

int randBounded(int low, int high)
{
    //cout << "In randBounded" << endl ;
    // Scales highest possible number to 1 (exclusive).
    static constexpr double scaleLow {1.0 / (RAND_MAX + 1.0) } ;

    // Scale to max (inclusive).
    return low + static_cast<int>((high - low + 1) * (rand() * scaleLow)) ;
}

void printRandomBounded(int nums, int cols,int low,int high)
{
    cout << "Bounded sytem clock method: " << endl ;
    for (int ii = 1 ; ii <= nums ; ii++)
    {
        cout << randBounded(low,high) << '\t' ;
        if (ii % cols == 0)
            cout << endl ;
    }
}

int main()
{
    int cols = 5 ;
    int maxiter = 10 ;
    printRandom(maxiter, cols, true, 6969) ;
    printRandom(maxiter, cols, false, 6969) ;

    // As you can see, these sequences are always identical since the numbers
    // can be predicted in a deterministic way from the seed number.
    // One way to get around this is the slock system. std::time() returns the seconds
    // since midnight Jan 1 1970.

    printRandomClock(maxiter, cols) ;

    // Now we will return an random number between an interval.
    printRandomBounded(maxiter,cols,0,6) ;

    /*
    A good PRNG should:
        1) Follow the desired distributiion (uniform, bell, long tail, etc.)
        2) Exhibit random behaviour. The sequence should not be predictable.
        3) Good dimensional distribution of numbers.
        4) Should have a long period for all seed numbers. All PRNG are periodic.
        When the starting seed is encountered and used as input again, the sequence will repeat.
    */
    std::cout << Random::get(1, 6) << '\n';

    return 0;
}
