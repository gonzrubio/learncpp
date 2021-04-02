#pragma once
#ifndef DECK_H
#define DECK_H

#include <array>
class Card;

class Deck {
public:
	using array_type = std::array<Card, 52>;
	using idx_type = std::size_t;
private:
	array_type m_deck;
	idx_type m_cardIndex{ 0 };
public:
	Deck();
	void print() const;
	const Card& dealCard() ;
	void shuffle();
};

#endif // !DECK_H


