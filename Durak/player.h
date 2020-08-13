#pragma once

#include <vector>
#include "deck.h"

class Player {
private:   
    std::vector<Card> m_hand;
    Card m_trump;

public:
    virtual std::vector<Card> getHand() const = 0;
    virtual Card* playCard() = 0;
    virtual Card* getMinTrump() const = 0;
    virtual void takeCard(const Card& card) = 0;  // ??
    virtual void printHand() const= 0; // ??
};