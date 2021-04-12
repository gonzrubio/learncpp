#include "IntArray.h"
#include <cassert>

IntArray::IntArray(int size = 0) : m_size{ size }, m_data{ nullptr } {
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
