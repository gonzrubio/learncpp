#include "Card.h"
#include "Deck.h"
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

Deck::Deck() {
    idx_type card{ 0 };
    auto suits{ static_cast<idx_type>(CardSuit::MAX_SUITS) };
    auto ranks{ static_cast<idx_type>(CardRank::MAX_RANKS) };

    for (idx_type suit{ 0 }; suit < suits; ++suit) {
        for (idx_type rank{ 0 }; rank < ranks; ++rank) {
            m_deck[card++] = { static_cast<CardRank>(rank), static_cast<CardSuit>(suit) };
        }
    }
}

void Deck::print() const {
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }
    std::cout << '\n';
}

const Card& Deck::dealCard() {
    assert(m_cardIndex < m_deck.size());
    return m_deck[m_cardIndex++];
}

void Deck::shuffle() {
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

