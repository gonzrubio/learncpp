#pragma 
#include "Person.h"

class BaseballPlayer : public Person {
public:
	double m_batting_average;
	int m_home_runs;
	BaseballPlayer() = default;
	BaseballPlayer(double batting_average, int home_runs);
};

