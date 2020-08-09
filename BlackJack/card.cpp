#include <iostream>
#include <cassert>
#include "card.h"
#include "constants.h"

Card::Card() = default;

Card::Card(cardType::CardRank rank, cardType::CardSuit suit)
    :   m_rank{ rank }
    ,   m_suit{ suit }
{
}

int Card::value() const{
    if (m_rank <= cardType::CardRank::RANK_10){
        return (static_cast<int>(m_rank) + constants::deckFirstCard);
    }
 
    switch (m_rank){
        case cardType::CardRank::RANK_JACK:
        case cardType::CardRank::RANK_QUEEN:
        case cardType::CardRank::RANK_KING:
            return 10;
        case cardType::CardRank::RANK_ACE:
            return 11;
        default:
          assert(false && "should never happen");
            return 0;
    }
}

void Card::print() const{
    switch (m_rank){
        case cardType::CardRank::RANK_2:
            std::cout << '2';
            break;
        case cardType::CardRank::RANK_3:
            std::cout << '3';
            break;
        case cardType::CardRank::RANK_4:
            std::cout << '4';
            break;
        case cardType::CardRank::RANK_5:
            std::cout << '5';
            break;
        case cardType::CardRank::RANK_6:
            std::cout << '6';
            break;
        case cardType::CardRank::RANK_7:
            std::cout << '7';
            break;
        case cardType::CardRank::RANK_8:
            std::cout << '8';
            break;
        case cardType::CardRank::RANK_9:
            std::cout << '9';
            break;
        case cardType::CardRank::RANK_10:
            std::cout << 'T';
            break;
        case cardType::CardRank::RANK_JACK:
            std::cout << 'J';
            break;
        case cardType::CardRank::RANK_QUEEN:
            std::cout << 'Q';
            break;
        case cardType::CardRank::RANK_KING:
            std::cout << 'K';
            break;
        case cardType::CardRank::RANK_ACE:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
    }

    #if defined(_WIN32) || defined(MSDOS)
    std::cout << char(static_cast<char>(m_suit) + constants::toAscii);
    #else
    switch (m_suit){
        case cardType::CardSuit::SUIT_HEART:
            std::cout << "\xE2\x99\xA5";
            break;
        case cardType::CardSuit::SUIT_DIAMOND:
            std::cout << "\xE2\x99\xA6";
            break;
        case cardType::CardSuit::SUIT_CLUB:
            std::cout << "\xE2\x99\xA3";
            break;
        case cardType::CardSuit::SUIT_SPADE:
            std::cout << "\xE2\x99\xA0";
            break;
        default:
            std::cout << '?';
            break;
    }
    #endif
  }
 
