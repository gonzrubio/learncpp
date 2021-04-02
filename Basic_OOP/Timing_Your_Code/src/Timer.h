#pragma once
#ifndef TIMER_H
#define TIMER_H

#include <chrono> // for std::chrono functions

class Timer {
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer(); // constructor. Initializes to current time
	void reset(); // Resets to current time
	double elapsed() const; //Returns elapsed time in seconds
};

#endif

