#include <random>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include "deck.h"

Deck::Deck(const DeckSize& size) {
    auto suitStart{ static_cast<int>(Card::CardSuit::start) };
    auto suitEnd{ static_cast<int>(Card::CardSuit::end) };
    
    auto rankStartBig{ static_cast<int>(Card::CardRank::start_big) };
    auto rankStartSmall{ static_cast<int>(Card::CardRank::start_big) };
    auto rankEnd{ static_cast<int>(Card::CardRank::start_big) };

    for(int i{ suitStart }; i < suitEnd; ++i) {
        int start;
        if(size == DeckSize::big) {
            start = rankStartBig;
        } else if(size == DeckSize::small) {
            start = rankStartSmall;
        }
        for(int j{start}; j < rankEnd; ++j) {
            m_deck.push_back({static_cast<Card::CardRank>(j), static_cast<Card::CardSuit>(i)});
        }
    } 
}

Card Deck::getCard() {
    if(!m_deck.empty()){
        Card temp = m_deck.back();
        m_deck.pop_back();
        return temp;
    }
    throw std::runtime_error("Deck is empty!!!");
}

Card Deck::getRandomCard() {
    std::random_device rd;
    static std::mt19937_64 mt{ rd() };
    std::uniform_int_distribution dist{0, 35};

    auto randIndex = dist(mt);
    Card temp = m_deck[randIndex];
    std::swap(m_deck[randIndex], m_deck.back());
    m_deck.pop_back();
    return temp;
}

void Deck::addCardToDeck(const Card& card) {
    std::random_device rd;
    static std::mt19937_64 mt{ rd() };
    std::uniform_int_distribution dist{0, 34};

    auto randIndex = dist(mt);
    m_deck.emplace_back(card);
    std::swap(m_deck[randIndex], m_deck.back());
}

void Deck::shuffle() {
    static std::mt19937_64 mt{ std::mt19937_64::result_type(std::time(nullptr))};
    std::shuffle(begin(m_deck), end(m_deck), mt);
}
