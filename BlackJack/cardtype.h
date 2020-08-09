#pragma once

namespace cardType{
    enum class CardSuit : int
    {
      SUIT_HEART,
      SUIT_DIAMOND,
      SUIT_CLUB,
      SUIT_SPADE,
    
      MAX_SUITS
    };
    
    enum class CardRank : int
    {
      RANK_2,
      RANK_3,
      RANK_4,
      RANK_5,
      RANK_6,
      RANK_7,
      RANK_8,
      RANK_9,
      RANK_10,
      RANK_JACK,
      RANK_QUEEN,
      RANK_KING,
      RANK_ACE,
    
      MAX_RANKS
    };
}