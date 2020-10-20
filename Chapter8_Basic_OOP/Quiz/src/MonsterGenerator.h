#pragma once
#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

class MonsterGenerator {
public:
	// Generate a random number between min and max (inclusive)
	// Assumes std::srand() has already been called
	// Assumes max - min <= RAND_MAX
	static int getRandomNumber(int min, int max);
	static Monster generateMonster();
};



#endif // !MONSTERGENERATOR_H