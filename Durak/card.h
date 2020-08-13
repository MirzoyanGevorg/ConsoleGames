#pragma once

class Card {
public:
    enum class CardRank {
        start_big = 0,
        two = 0,
        three,
        four,
        five,
        start_small = 4,
        six = 4,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        ace,
        end
    };

    enum class CardSuit {
        start = 0,
        heart = 0,
        diamond,
        club,
        spade,
        end
    };

private:
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    Card();
    Card(CardRank rank, CardSuit suit);
    void print() const;
    bool operator<(const Card& card) const;
};