#include "player.h"

int Player::score() const{
    return m_score;
}
 
bool Player::isBust() const{
    return (m_score > constants::maxScore);
}

const std::vector<Card>& Player::hand() const{
    return m_cards;
}

void Player::drawCard(Deck& deck){
    
    m_cards.emplace_back(deck.dealCard());
    m_score += m_cards[m_cards.size() - 1].value();
}