#pragma once

#include "deck.h"
#include "player.h"

class GameLogic{
private:
    Player m_player;
    Player m_dealer;
public:
    bool playerWantsHit();
    bool playerTurn(Deck& deck);
    bool dealerTurn(Deck& deck);
    bool playBlackjack(Deck& deck);
    void printCards(const Player& player) const;
    void printPlayerCards() const;
    void printDealerCards() const;
    void printGameScore() const;
};