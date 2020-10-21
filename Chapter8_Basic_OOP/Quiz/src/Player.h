#pragma once
#ifndef PLAYER_H
#define PLAYER_H

constexpr int maximumScore{ 21 }; // Maximum score before losing.
constexpr int minimumDealerScore{ 17 }; // Minimum score that the dealer has to have.

class Player {
private:
    int m_score{};
public:
    //void drawCard(Deck& deck) { m_score += deck.dealCard().value(); }
    void drawCard(Deck& deck);
    int score() const { return m_score; }
    bool isBust() const;
};

#endif // !PLAYER_H

