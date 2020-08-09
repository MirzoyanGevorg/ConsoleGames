#pragma once

#include "deck.h"
#include <vector>

class Player{
    private:
        int m_score{};
        std::vector<Card> m_cards;
    
    public:
        int score() const;
        bool isBust() const;
        const std::vector<Card>& hand() const;
        void drawCard(Deck& deck);
};