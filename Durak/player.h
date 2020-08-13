#pragma once

#include <vector>
#include "deck.h"

class Player {
private:   
    std::vector<Card> m_hand;
    Card m_trump;

public:
    virtual std::vector<Card> getHend() const = 0;
    virtual void takeCard(Deck& deck) = 0;  // ??
    virtual Card* playCard() = 0;
    virtual void printHand() = 0; // ??
};