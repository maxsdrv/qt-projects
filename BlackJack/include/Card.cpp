#include "Card.h"

Card::Card(Card::rank r, Card::suit s, bool pos) : m_Rank(r), m_Suit(s),
                                                   m_PositionUp(pos) {}

void Card::Flip() {
    m_PositionUp = !(m_PositionUp);
}

int Card::GetValue() const {
    int value = 0;
    if (m_PositionUp) {
        value = getRank().second;
        if (value > 10) {
            value = 10;
        }
    }

    return value;
}

std::ostream &operator<<(std::ostream &os, const Card& card) {
    if (card.m_PositionUp) {
        os << card.getRank().first << " ";
    }
    else {
        os << "XX";
    }

    return os;
}

std::pair<std::string, int> Card::getRank() const{
    static std::unordered_map<Card::rank, std::pair<std::string, int>> map{
            {Card::rank::ACE, {"ACE", 11}},
            {Card::rank::TWO, {"TWO", 2}},
            {Card::rank::THREE, {"THREE", 3}},
            {Card::rank::FOUR, {"FOUR", 4}},
            {Card::rank::FIVE, {"FIVE", 5}},
            {Card::rank::SIX, {"SIX", 6}},
            {Card::rank::SEVEN, {"SEVEN", 7}},
            {Card::rank::EIGHT, {"EIGHT", 8}},
            {Card::rank::NINE, {"NINE", 9}},
            {Card::rank::TEN, {"TEN", 10}},
            {Card::rank::JACK, {"JACK", 2}},
            {Card::rank::QUEEN, {"QUEEN", 3}},
            {Card::rank::KING, {"KING", 4}}
    };

    return map[m_Rank];
}

