#pragma once

#include "cardtype.h"

class Card{
    private:
        cardType::CardRank m_rank{};
        cardType::CardSuit m_suit{};

    public:
        Card();
        Card(cardType::CardRank rank, cardType::CardSuit suit);
        int value() const;
        void print() const;
        // TODO operator << 
};