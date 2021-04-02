// We can encapsulate the timing functionality into a class.

#include "Timer.h"
#include <algorithm> // for std::sort
#include <array>
#include <cstddef> // for std::size_T
#include <iostream>
#include <numeric> // for std::iota

void selection_sort(std::array<int, 1000>& arr) {
    for (std::size_t ii{ 0 }; ii < 1000 - 1; ii++) {
        std::size_t kk{ ii };
        for (std::size_t jj{ ii + 1 }; jj < 1000; jj++) {
            if (arr[jj] < arr[kk]) {
                kk = jj;
            }
        }
        std::swap(arr[ii], arr[kk]);
    }
}

int main() {
    // Sort an array of 1000 elements sorted in reverse order. array = [1000, 999, ... , 1]
    std::array<int, 1000> arr;
    std::iota(arr.rbegin(), arr.rend(), 1);

    Timer t;
    selection_sort(arr);
    std::cout << "The elapsed time using selection sort is: " << t.elapsed() << " seconds." << std::endl ;
    t.reset();
    // Sort in non-ascending order. Reverses the array.
    std::sort(arr.begin(), arr.end(), std::greater<int>()); 
    std::cout << "The elapsed time using std::sort is: " << t.elapsed() << " seconds." << std::endl;
}
