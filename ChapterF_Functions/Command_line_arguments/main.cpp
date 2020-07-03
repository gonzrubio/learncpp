#include <iostream>

/*
    Command line arguments provide a great way for users or other programs
    to pass input data into a program at startup. Consider making any input data
    that a program requires at startup to operate a command line parameter. If the
    command line isnt passed in, you can always detect that and ask the user for input.
*/

int main(int argc, char *argv[])
{
    std::cout << "There are " << argc << " arguments:" << "\n" ;
    for (int ii = 0 ; ii < argc ; ii++)
    {
        std::cout << ii << " " << argv[ii] << "\n" ;
    }

    return 0;
}
