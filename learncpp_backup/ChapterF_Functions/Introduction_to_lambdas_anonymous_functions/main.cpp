#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <functional> // for std::function

/*
    A lambda expression (a lambda or closure) allows us to define an anonymous function
    inside another function.

    Syntax:
    [ captureClause ] ( parameters ) -> returnType
    {
        statements ;
    }
*/

void ex0()
{
    std::array<std::string,4> words{"apple", "banana", "walnut", "lemon" } ;

    // std::find_if takes in iterators (begining and end + 1) and a function pointer.
    // Instead of defining a function, can use a lambda.
    // Declare and initialize a variable that contains a pointer to the elemenet
    // with the first appearance of the specific string. Auto makes things easiest.
    auto found{ std::find_if(words.begin(),words.end(),
                             [](std::string str) // Here is our lambda, no capture clause.
                             // We omit the return type for conciseness, but since != operator
                             // reutrns a bool, our lamnda will return a bool too.
                             {
                                 // Statement. Search for "nut" from the star or the element in the array
                                 // if not found, return std::string::npos.
                                 return (str.find("nut") != std::string::npos) ;
                             }) } ;
    if (found == words.end())
        std::cout << "Not found\n" ;
    else
        std::cout << "Found " << *found << ".\n" ;

    // Note: Here we use the lambda right where we need it, we call it function literal.
}

void ex1() // Check if all elements in the array are even.
{
    // We can initialize a variable with a literal value or function pointer for use later,
    // we can also initialize a lambda variable with a lambda definition and use it later.
    auto isEven{
      [](int i)
      {
        return ((i % 2) == 0);
      }
    };

    std::array<int,3> arr{13,69,420} ;
    //std::all_of(arr.begin(), arr.end(), isEven) ;
    if (std::all_of(arr.begin(), arr.end(), isEven)) ;
        std::cout << "All elements are even.\n" ;
}

void ex2()
{
    // Sometimes we want to store a lambda for later use but dont know the return-type.
    // If the lambda has an empty capture clause, we can use a regular funciton pointer.
    // However, if it has a capture clause, function pointers wont work anymore.
    // We can use std::function for lambdas even if they are capturing something.

    // Define and initialize a lambda variable with a lambda definition and use it later.
    // Store the lambda using std::function, call it addPair (the lambda variable).
    // The lambda variable is of type: pointer to a function that returns a double and take in two doubles.
    // This lambda variable contains a function that returns a double and takes in two doubles.
    std::function<double(double,double)> addPair{
      [](double a, double b){ // lambda definition
        return (a+b) ;
      }
    } ;

    double a{2} ;
    double b{2} ;
    std::cout << a << " + "  << b << " = " << addPair(a,b) << "\n" ;

    // The only way of using the lambdas actual type is by means of the auto keyword.
    // auto has the benefit of having no overhead compared to std::function.
    // Using auto. Stores the lambda with its real type.
    auto addNumbers{
      [](double a, double b) {
          return (a + b);
        }
    };
    std::cout << a << " + "  << b << " = " << addNumbers(a,b) << "\n" ;

    // If we cant use auto, use std::function.
}

// struct Student that stores the name and points of the student.
struct Student
{
    std::string name ;
    int points ;
};

void ex3()
{
    // Create an array of students.
    // Since we have an array that holds a struct, use double parenthesis.
    std::array<Student, 8> arr{
    {{ "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
    };

    /*std::function<bool(int,int)> fcnMax{
      [](int a, int b){
          return (a<b) ;
        }
    } ;*/

    // Use std::max_element to find the student with the most points.
    // std::max_element takes the begin and end of a list, and a function that takes 2 parameters
    // and returns true if the first argument is less than the second.
    auto best{std::max_element( arr.begin(), arr.end(), [](const auto& a, const auto& b){
                               return (a.points < return b.points) ;
                               })
                               } ;
    std::cout << best.name << " is the best studnet \n" ;
}

int main()
{
    //ex0() ;
    //ex1() ;
    //ex2() ;
    //ex3() ;

    return 0;
}
