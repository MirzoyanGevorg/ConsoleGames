#pragma once

#include <array>
#include "constants.h"
#include "card.h"
#include "cardtype.h"

class Deck{
    public:
        using arr = std::array<Card, constants::maxCards>;
        using index = arr::size_type;

    private:
        arr m_deck{};
        index m_cardIndex{ 0 };

    public:
        Deck();
        const Card& dealCard();
        void shuffle();
        void print() const;
};