#pragma once

#include "player.h"
#include <string>

class HumanPlayer : Player
{
private:
    std::string name;
public:
    HumanPlayer();
    ~HumanPlayer();

    std::vector<Card> getHand() const override;
    Card* playCard() override;
    Card* getMinTrump() const override;
    void takeCard(const Card& card) override;  // ??
    void printHand() const override; // ??
};
