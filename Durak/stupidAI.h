#pragma once

#include "player.h"
#include <string>

class StupidAI{
private:
    std::string name;
public:
    StupidAI();
    ~StupidAI();
    std::vector<Card> getHand() const override;
    Card* playCard() override;
    Card* getMinTrump() const override;
    void takeCard(const Card& card) override;  // ??
    void printHand() const override; // ??
};