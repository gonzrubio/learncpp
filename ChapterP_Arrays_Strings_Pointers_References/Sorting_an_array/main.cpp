#include <iostream>

/*
    1) Starting at index 0, find the smallest/largest element in the array.
    2) Swap that element with the one at index 0.
    3) Repeat 1)&2) starting from the next index (until we run out of elements).
*/

using namespace std;

void swapMine(int &x, int &y)
{
    int temp{y} ;
    y = x ;
    x = temp ;
}

void testswapMine()
{
    int x{ 69 } ;
    int y = { 420 } ;
    cout << "Before swapMine(): x = " << x << " and y = " << y << endl ;
    swapMine(x,y) ;
    cout << "After swapMine(): x = " << x << " and y = " << y << endl ;
}

void selectionSort(int *arr, int len, bool method)
{
    if (method)
    {
        cout << endl << "Selection sort (ascending)..." ;
        for (int idxStart = 0 ; idxStart < len - 1 ; idxStart++)
        {
            int idxSmallest{idxStart} ;
            for (int idxCurrent = idxStart + 1 ; idxCurrent < len ; idxCurrent++)
            {
                if (arr[idxCurrent] < arr[idxSmallest])
                    idxSmallest = idxCurrent ;
            }
            swapMine(arr[idxStart],arr[idxSmallest]) ;
        }
    }
    else
    {
        cout << endl << "Selection sort (descending)..." ;
        for (int idxStart = 0 ; idxStart < len - 1 ; idxStart++)
        {
            int idxLargest{idxStart} ;
            for (int idxCurrent = idxStart + 1 ; idxCurrent < len ; idxCurrent++)
            {
                if (arr[idxCurrent] > arr[idxLargest])
                    idxLargest = idxCurrent ;
            }
            swapMine(arr[idxStart],arr[idxLargest]) ;
        }
    }
}

int main()
{
    // testswapMine() ;
    int arr0[]{30, 50, 20, 10, 10, 40, 80, 30, 50} ;

    cout << "Array before sorting: " ;
    for (const int element : arr0)
    {
        cout << element << " " ;
    }

    int len = sizeof(arr0) / sizeof(arr0[0]) ;

    selectionSort(arr0,len,true) ;

    cout << endl << "Array after sorting: " ;
    for (const int element : arr0)
    {
        cout << element << " " ;
    }

    selectionSort(arr0,len,false) ;

    cout << endl << "Array after sorting: " ;
    for (const int element : arr0)
    {
        cout << element << " " ;
    }

    return 0;
}
