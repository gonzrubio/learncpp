#pragma once
#include <cassert>

class IntArray {
private:
	int m_size;   // size of the array.
	int* m_data;  // For dynamic allocation.
public:
	IntArray(int size = 0);
	~IntArray() { // Destructor that de-allocates any dynamically allocated data.
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object
		// will be destroyed immediately after this function anyway.
	}
	void erase(); // Function to erase the array and set length to zero.
	int& operator[](const int index); // Access element at a given index in the array.
	const int size() const; // Function to return the length of the current array.
	void reallocate(const int new_size);// Resizes the array. Any existing elements will be destroyed.
};

