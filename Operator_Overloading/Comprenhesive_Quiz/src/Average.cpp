#include "Average.h"

Average& Average::operator+=(int num) {
	m_sum += num; // Increase sum.
	m_len++;      // Increse number of elements seen.
	return *this; // For chaining.
}


