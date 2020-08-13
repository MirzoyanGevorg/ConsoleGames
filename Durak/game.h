#pragma once

#include "humanPlayer.h"
#include "stupidAI.h"
#include "smartAI.h"
#include "deck.h"
#include <vector>
#include <stack>

class Game{
private:
    std::stack<Card> m_talon, m_trash;
    std::vector<Player> m_players;
    HumanPlayer m_player;
    StupidAI m_stupidBot;
    SmartAI m_smartBot;

public:
    void startGame() const;
    
};