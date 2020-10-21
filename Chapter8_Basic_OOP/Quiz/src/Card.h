#pragma once
#ifndef CARD_H
#define CARD_H

enum class CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum class CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

class Card {
private:
	CardSuit m_suit;
	CardRank m_rank;
public:
	Card(CardRank rank=CardRank::RANK_2, CardSuit suit=CardSuit::SUIT_CLUB) : m_suit{suit}, m_rank{rank} {}
	void print() const;
	int value() const;
};

#endif // !CARD_H

