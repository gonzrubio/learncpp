#pragma once
#include <cassert>
#include <cstdint>
#include <iostream>

class Average {
private:
	std::int_least32_t m_sum;
	std::int_least8_t m_len;
public:
	Average(std::int_least32_t sum = 0.0, std::int_least8_t len = 0.0) :
		m_sum{ sum }, m_len{ len } {
		assert(m_len >= 0.0);
	}

	Average(const Average& original) :
		m_sum{ original.m_sum }, m_len{ original.m_len } {
	}

	Average& operator+=(int num);
	friend std::ostream& operator<<(std::ostream& out, const Average& average);
};

