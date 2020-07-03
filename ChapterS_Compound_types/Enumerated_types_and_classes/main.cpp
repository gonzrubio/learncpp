#include <iostream>

using namespace std;

// Define an enumerated type named Color.
// Enumerated type names start with capital letters.
enum Color
{
    // Here are the enumerators.
    // These are all the possible values the enumerated type Color can hold.
    // Enumerators are written in all caps.
    // Enumerators are given the enumerated type name as prefix.

    COLOR_BLACK,   // = 0 (By default all star with zero).
    COLOR_RED,     // = 1
    COLOR_BLUE,    // = 2
    COLOR_GREEN,   // = 3
    COLOR_WHITE,   // = 4
    COLOR_CYAN,    // = 5
    COLOR_YELLOW,  // = 6
    COLOR_MAGENTA  // = 7

} ;

// Enumerated type Animal
enum Animal
{
    // It is possible to explicitly assign the value of the enumerators (integers).
    // Any non-assigned enumerators are given a value greater than the previous one.
    ANIMAL_CAT = -3,
    ANIMAL_DOG = -2,
    ANIMAL_LION,
    ANIMAL_SNAKE = 5,
    ANIMAL_SQUID
};

enum AlgoType
{
    ALGOTYPE_1,
    ALGOTYPE_2,
    ALGOTYPE_3,
    ALGOTYPE_4
} ;

void doSomething(AlgoType algo)
{
    if (algo == ALGOTYPE_1)
        cout << "Process data using algo # 1." << endl ;
    else if (algo == ALGOTYPE_2)
        cout << "Process data using algo # 2." << endl ;
    else if (algo == ALGOTYPE_3)
        cout << "Process data using algo # 3." << endl ;
    else if (algo == ALGOTYPE_4)
        cout << "Process data using algo # 4." << endl ;
}


/*
    Best practice: Do not assign the value to the enumerators.
    Use the default 0,1,2,...,n.
*/

/*
    ALWAYS USE enumerated classes over enumerated types.
*/

enum class Colour
{
    RED,
    PURPLE,
    PINK
};

int main()
{
    // Define a few variables of enumerated type Color.
    // enumerated type variable = enumerator ;
    Color paint = COLOR_WHITE ;
    Color house = COLOR_BLUE ;
    Color car = COLOR_RED ;

    cout << "The symbolic constant of  the enumerator COLOR_WHITE is: " << paint << " ." << endl ;

    // Define a couple of variables of enumerated type Animal.
    Animal lion = ANIMAL_LION ;
    Animal squid = ANIMAL_SQUID ;

    cout << "The value for lion is: " << lion << " ." << endl ;
    cout << "The value for squid is: " << squid << " ." << endl ;

    // Enumerate types evaluate to integers so they can be assigned to integer variables.
    int enumInteger = COLOR_MAGENTA ;
    cout << "COLOR_MAGENTA was asigned to enumInteger: " << enumInteger << " ." << endl ;

    // Enumerated types are useful when writing functions to do specific things like chosing an algorithm to do something.
    AlgoType method1 = ALGOTYPE_1 ;
    doSomething(method1) ;
    AlgoType method2 = ALGOTYPE_2 ;
    doSomething(method2) ;
    AlgoType method3 = ALGOTYPE_3 ;
    doSomething(method3) ;
    AlgoType method4 = ALGOTYPE_4 ;
    doSomething(method4) ;

    // Enumerated classes are type safe so wont do implicit conversion to int type.

    Colour colour = Colour::RED ;
    cout << "The enumerator RED in the enumeration class Colour has a value of: " << static_cast<int>(colour) << " ." << endl ;
    cout << "Since it is strongly scoped, it had to be acced via Colour::RED" << endl ;


    return 0;
}
