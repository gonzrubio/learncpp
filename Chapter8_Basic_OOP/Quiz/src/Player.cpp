#include "Card.h"
#include "Deck.h"
#include "Player.h"

void Player::drawCard(Deck& deck) { m_score += deck.dealCard().value(); }
bool Player::isBust() const { return (m_score > maximumScore); }
