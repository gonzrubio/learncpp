#include "Card.h"
#include <cassert>
#include <iostream>

void Card::print() const {
	switch (m_rank) {
	case CardRank::RANK_2:
		std::cout << '2';
		break;
	case CardRank::RANK_3:
		std::cout << '3';
		break;
	case CardRank::RANK_4:
		std::cout << '4';
		break;
	case CardRank::RANK_5:
		std::cout << '5';
		break;
	case CardRank::RANK_6:
		std::cout << '6';
		break;
	case CardRank::RANK_7:
		std::cout << '7';
		break;
	case CardRank::RANK_8:
		std::cout << '8';
		break;
	case CardRank::RANK_9:
		std::cout << '9';
		break;
	case CardRank::RANK_10:
		std::cout << 'T';
		break;
	case CardRank::RANK_JACK:
		std::cout << 'J';
		break;
	case CardRank::RANK_QUEEN:
		std::cout << 'Q';
		break;
	case CardRank::RANK_KING:
		std::cout << 'K';
		break;
	case CardRank::RANK_ACE:
		std::cout << 'A';
		break;
	default:
		std::cout << '?';
		break;
	}

	switch (m_suit) {
	case CardSuit::SUIT_CLUB:
		std::cout << 'C';
		break;
	case CardSuit::SUIT_DIAMOND:
		std::cout << 'D';
		break;
	case CardSuit::SUIT_HEART:
		std::cout << 'H';
		break;
	case CardSuit::SUIT_SPADE:
		std::cout << 'S';
		break;
	default:
		std::cout << '?';
		break;
	}
}

int Card::value() const {
	if (m_rank <= CardRank::RANK_10) {
		return (static_cast<int>(m_rank) + 2);
	}

	switch (m_rank) {
	case CardRank::RANK_JACK:
	case CardRank::RANK_QUEEN:
	case CardRank::RANK_KING:
		return 10;
	case CardRank::RANK_ACE:
		return 11;
	default:
		assert(false && "should never happen");
		return 0;
	}
}