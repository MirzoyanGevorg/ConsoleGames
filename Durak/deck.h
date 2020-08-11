#pragma once

#include <vector>
#include "card.h"

class Deck{
private:
    enum class DeckSize {
        small,
        big
    };
    std::vector<Card> m_deck{};

public:
    Deck(const DeckSize& size); 
    Card getCard();
    Card getRandomCard();
    void addCardToDeck(const Card& card);
    void shuffle();
};