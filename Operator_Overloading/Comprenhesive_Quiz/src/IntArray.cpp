#include "IntArray.h"
#include <cassert>

int& IntArray::operator[](int index) {
    assert(index >= 0 && index < m_size && "Attempted to access and element out of bounds.");
    return m_array[index];
}
