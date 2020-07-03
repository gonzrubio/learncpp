#include <iostream>
#include <iterator> // for std::begin and std:: end
#include <algorithm> // for std::count_if

using namespace std;

bool isOne(int a)
{
    if (a==1)
        return true ;
    else
        return false ;
}

int countOnes(int arr[],int len)
{
    // We can use pointe arithmetic to iterate through an array.
    // Declare and Initialize counter variable.
    int cnt{0} ;
    //int *ptr{arr} ;

    // array decay to pointer. So we can start at location in memory of first element. Where pointer points to.
    // (ptr + arrayLenght) because last = start + arrayLength.
    for (int *ptr{ arr } ; ptr < arr + len ; ++ptr)
        {
            //Dereference pointer to get character.
            if (isOne(*ptr))
            {
                ++cnt ;
            }
        }
    return cnt ;
}

void printCountOnes(int arr[], int len, int cnt)
{
    // This works because [] is equivalent to pointer addition followed by dereferencing.
    cout << "The array [" << arr[0] ;
    for (int ii = 1 ; ii < len ; ii++)
    {
        cout << "," << arr[ii] ;
    }
    cout << "] has " << cnt << " ones." << endl ;
}

int* findInt(int *start, int*last, int num)
{
    for (int *iptr = start; iptr < last; iptr++)
    {
        if (*iptr == num)
            return iptr ;
    }
    return last ;
}


int main()
{

    int arr[]{1,2,3,1,2,3,1,2,3,1,1,1,1,1} ;
    int len{sizeof(arr)/sizeof(arr[0])} ;
    cout << "Using a pointer to iterate through an array:" << endl ;
    int cnt{countOnes(arr,len)} ;
    printCountOnes(arr, len, cnt) ;

    // begin() returns an iterator (pointer) that ponts at the first element
    // end() returns an iterator (pointer) that would be after the last
    auto numOnes{count_if(begin(arr), end(arr), isOne)} ;
    cout << "Using the algorithms library:" << numOnes << endl ;

    cout << "Find value problem now" << endl ;
    int arr2[]{ 2, 5, 4, 10, 8, 20, 16, 40} ;

    int *pos{findInt(begin(arr2),end(arr2),20)} ;
    if (pos != end(arr2))
        cout << *pos << endl ;
    else
        cout << "not found." << endl ;

    return 0;
}
