#include "Monster.h"
#include "MonsterGenerator.h"
#include <array>
#include <random>

class Monster;

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int MonsterGenerator::getRandomNumber(int min, int max) {
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

Monster MonsterGenerator::generateMonster() {
	auto type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)) };
	int hitPoints{ getRandomNumber(1, 100) };

	// If your compile is not C++17 capable, use std::array<const char*, 6> instead.
	static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
	static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

	// Without the cast, compilers with a high warning level complain about
	// an implicit cast from a signed to an unsigned integer.
	auto name{ s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };
	auto roar{ s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };

	return { type, name, roar, hitPoints };
}