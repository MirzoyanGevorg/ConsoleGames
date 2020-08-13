#include <iostream>
#include <cassert>
#include "card.h"

Card::Card() = default;

Card::Card(CardRank rank, CardSuit suit)
    :   m_rank { rank }
    ,   m_suit { suit }
{

}

bool Card::operator<(const Card& card) const {
    if(static_cast<int>(m_suit) == static_cast<int>(card.m_suit)) {
        return static_cast<int>(m_rank) < static_cast<int>(card.m_rank);
    } else {
        std::cout << "";
    }
}

void Card::print() const {
    switch (m_rank)
    {
        case CardRank::two:
            std::cout << '2';
            break;
        case CardRank::three:
            std::cout << '3';
            break;
        case CardRank::four:
            std::cout << '4';
            break;
        case CardRank::five:
            std::cout << '5';
            break;
        case CardRank::six:
            std::cout << '6';
            break;
        case CardRank::seven:
            std::cout << '7';
            break;
        case CardRank::eight:
            std::cout << '8';
            break;
        case CardRank::nine:
            std::cout << '9';
            break;
        case CardRank::ten:
            std::cout << 'T';
            break;
        case CardRank::jack:
            std::cout << 'J';
            break;
        case CardRank::queen:
            std::cout << 'Q';
            break;
        case CardRank::king:
            std::cout << 'K';
            break;
        case CardRank::ace:
            std::cout << 'A';
            break;
        default:
            assert(false && "There is no such rank");
            break;
    }

    #if defined(_WIN32) || defined(MSDOS)
        std::cout << char(static_cast<char>(m_suit) + constants::toAscii);
    #else
    switch (m_suit){
        case CardSuit::heart:
            std::cout << "\xE2\x99\xA5";
            break;
        case CardSuit::diamond:
            std::cout << "\xE2\x99\xA6";
            break;
        case CardSuit::club:
            std::cout << "\xE2\x99\xA3";
            break;
        case CardSuit::spade:
            std::cout << "\xE2\x99\xA0";
            break;
        default:
            assert(false && "There is no such suit");
            break;
    }
    #endif
}