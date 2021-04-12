#pragma once
#include <cassert>

class IntArray {
private:
	int m_size;   // size of the array.
	int* m_data;  // For dynamic allocation.
public:
	IntArray(int size);
	~IntArray() { // Destructor that de-allocates any dynamically allocated data.
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object
		// will be destroyed immediately after this function anyway.
	}
	void erase(); // Function to erase the array and set length to zero.
	int& operator[](const int index); // Access element at a given index in the array.
	const int size() const; // Function to return the length of the current array.
	void reallocate(const int new_size); // Resizes the array. Any existing elements will be destroyed.
	void resize(const int new_size); // Keeps any existing elements in the array when it is resized.
	void insert_before(const int value, const int index); //Insert value before element at index.
	void remove(const int index); // Remove element at index.
	void insert_at_beginning(const int value); // Insert element at the beginning of the array.
	void insert_at_end(const int value); // Insert element at the end of the array.
};

