#include <iostream>
#include "gameLogic.h"

bool GameLogic::playerWantsHit(){
    while (true){
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch){
            case 'h':
              return true;
            case 's':
              return false;
        }
    }
}

bool GameLogic::playerTurn(Deck& deck){
    while (true){
        std::cout << "You have: " << m_player.score(); printCards(m_player); std::cout<< '\n';

        if (m_player.isBust()){
            return true;
        }
        else
        {
            if (playerWantsHit()){
                m_player.drawCard(deck);
            }
            else{
                return false;
            }
        }
    }
}

bool GameLogic::dealerTurn(Deck& deck){
    while (m_dealer.score() < constants::minDealerScore){
        m_dealer.drawCard(deck);
    }
    
    return m_dealer.isBust();
}
 
bool GameLogic::playBlackjack(Deck& deck){
    m_dealer.drawCard(deck);
    
    std::cout << "The dealer is showing: " << m_dealer.score(); printCards(m_dealer); std::cout<< '\n';
    
    m_player.drawCard(deck);
    m_player.drawCard(deck);
    
    if (playerTurn(deck)){
        return false;
    }
    
    if (dealerTurn(deck)){
        return true;
    }
    
    return (m_player.score() > m_dealer.score());
}

void GameLogic::printCards(const Player& player) const{
    std::cout << '(';

    for(const auto& card: player.hand()){ 
        card.print();
    }
    
    std::cout << ')';
}

void GameLogic::printPlayerCards() const{
    //std::cout << "... ";
    printCards(m_player);
}

void GameLogic::printDealerCards() const{
    //std::cout << "... ";
    printCards(m_dealer);
}

void GameLogic::printGameScore() const{
    std::cout << "Game Score: You - Dealler ";
    std::cout << m_player.score();
    std::cout << " - ";
    std::cout << m_dealer.score();
    std::cout << std::endl; 
}