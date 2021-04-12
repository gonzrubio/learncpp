#include "IntArray.h"
#include <cassert>

IntArray::IntArray(int size=0) : m_size{ size }, m_data{ nullptr } {
	// Constructor for array of predetermined size. Empty array by default
	assert(size >= 0 && "Array size must be a non-negative integer.");
	if (m_size > 0) {
		m_data = new int[m_size];
	}
}

void IntArray::erase() {
	if (m_size > 0) {
		delete[] m_data;
		m_data = nullptr; // Otherwise it will be pointing at deallocated memory.
		m_size = 0;
	}
}

int& IntArray::operator[](const int index) {
	assert(index >= 0 && index < m_size && "Index out of bounds.");
	return m_data[index];
}

const int IntArray::size() const {
	return m_size;
}

void IntArray::reallocate(const int new_size) {
	assert(new_size >= 0 && "Size has to be a non-negative integer.");

	erase();
	if (new_size > 0) {
		m_size = new_size;
		m_data = new int[m_size];
	}
}

void IntArray::resize(const int new_size) {
	assert(new_size >= 0 && "Size has to be a non-negative integer.");

	if (new_size == m_size) { return; }

	if (new_size > 0) {
		// Allocate an array with the new_size.
		int* new_data{ new int[m_size] };

		// Copy all elements from the old array to the new array.
		for (int index{ 0 }; index < m_size; index++) {
			new_data[index] = m_data[index];
		}
		// Destroy the old array.
		delete[] m_data;

		// Assign m_data to point to the new array. Because data was dynamically allocated,
		// it won't be destroyed when it goes out of scope.
		m_data = new_data;
		m_size = new_size;
		return;
	}
	erase();
}

void IntArray::remove(const int index) {
	assert(index >= 0 && index <= m_size && "Index out of bounds.");

	// If this is the last element in the array, set the array to empty.
	if (m_size == 1) {
		erase();
		return;
	}

	// First create a new array one element smaller than the old array
	int* data{ new int[m_size - 1] };

	// Copy all of the elements up to the index
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	// Copy all of the values after the removed element
	for (int after{ index + 1 }; after < m_size; ++after)
		data[after - 1] = m_data[after];

	// Finally, delete the old array, and use the new array instead
	delete[] m_data;
	m_data = data;
	--m_size;
}

void IntArray::insert_at_beginning(const int value) {
	insert_before(value, 0);
}

void IntArray::insert_at_end(const int value) {
	insert_before(value, m_size);
}

void IntArray::insert_before(const int value, const int index) {
	assert(index >= 0 && index <= m_size && "Index out of bounds.");

	// First create a new array one element larger than the old array.
	int* data{ new int[m_size + 1] };

	// Copy all of the elements up to the index
	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	// Insert our new element into the new array
	data[index] = value;

	// Copy all of the values after the inserted element
	for (int after{ index }; after < m_size; ++after)
		data[after + 1] = m_data[after];

	// Finally, delete the old array, and use the new array instead
	delete[] m_data;
	m_data = data;
	++m_size;
}
