#pragma once
#include <cassert>

class IntArray {
private:
	int m_size;
	int* m_array{ nullptr };
public:
	IntArray(int size) : m_size{ size } {
		assert(m_size > 0 && "IntArray size should be a positive integer.");
		m_array = new int[m_size]{};
	}
	// Copy constructor that does a deep copy
	IntArray(const IntArray& array) :
		m_size{ array.m_size } {
		// Allocate a new array
		m_array = new int[m_size];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];
	}
	~IntArray() {
		delete[] m_array;
	}
	int& operator[] (const int index) {
		assert(index >= 0);
		assert(index < m_size);
		return m_array[index];
	}
	friend std::ostream& operator<<(std::ostream& out, const IntArray& array) {
		for (int count{ 0 }; count < array.m_size; ++count) {
			out << array.m_array[count] << ' ';
		}
		return out;
	}
	// Assignment operator that does a deep copy
	IntArray& operator= (const IntArray& array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_size = array.m_size;

		// Allocate a new array
		m_array = new int[m_size];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}
};

