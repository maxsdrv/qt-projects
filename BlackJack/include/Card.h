#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Card {
public:
    enum class suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    enum class rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    explicit Card(rank r = rank::ACE, suit s = suit::SPADES, bool pos = true);
    void Flip(); //переворачиваем карту
    [[nodiscard]]int GetValue() const; //возвращаем значение карты от 1 до 11
    [[nodiscard]]std::pair<std::string, int> getRank() const; //возвращаем пару название и ценность карты
    friend std::ostream& operator<<(std::ostream& os, const Card& card); //перегрузка оператора <<
private:
    suit m_Suit;
    rank m_Rank;
    bool m_PositionUp;
};


#endif //BLACKJACK_CARD_H
