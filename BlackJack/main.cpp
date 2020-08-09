#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "gameLogic.h"

int main(){
    Deck deck{};
    deck.shuffle();
    GameLogic game;
    
    if (game.playBlackjack(deck)) {
        std::cout << "You win! Your cards: ";
        game.printPlayerCards();
        std::cout << ", Dealer cards: ";
        game.printDealerCards();
        std::cout << std::endl;  
    }
    else{
        std::cout << "You lose! Your cards: ";
        game.printPlayerCards();
        std::cout << ", Dealer cards: ";
        game.printDealerCards();
        std::cout << std::endl; 
    }

    game.printGameScore();
    
    return 0;
}
   