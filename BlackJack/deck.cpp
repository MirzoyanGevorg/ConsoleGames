#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <cassert>
#include "deck.h"

Deck::Deck(){
    index card{ 0 };
 
    auto suits{ static_cast<index>(cardType::CardSuit::MAX_SUITS) };
    auto ranks{ static_cast<index>(cardType::CardRank::MAX_RANKS) };
 
    for (index suit{ 0 }; suit < suits; ++suit){
        for (index rank{ 0 }; rank < ranks; ++rank){
            m_deck[card] = { static_cast<cardType::CardRank>(rank), static_cast<cardType::CardSuit>(suit) };
            ++card;
        }
    }
}

const Card& Deck::dealCard(){
    assert(m_cardIndex < m_deck.size());
    return m_deck[m_cardIndex++];
}

void Deck::shuffle(){
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

void Deck::print() const{
    for (const auto& card : m_deck){
        card.print();
        std::cout << ' ';
    }
 
    std::cout << '\n';
}