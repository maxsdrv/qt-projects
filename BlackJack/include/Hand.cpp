#include "Hand.h"

Hand::Hand() {
    m_Cards.reserve(7);
}

void Hand::Add(Card *pCard) {
    auto card = std::make_shared<Card>(*pCard);
    m_Cards.push_back(card);
}

Hand::~Hand() = default;


int Hand::GetTotal() const {
    if (m_Cards.empty()) {
        return 0;
    }
    if (m_Cards[0]->GetValue() == 0) {
        return 0;
    }
    int total = 0;
    std::vector<std::shared_ptr<Card>>::const_iterator iterator;
    for (iterator = m_Cards.begin(); iterator != m_Cards.end(); ++iterator) {
        total += (*iterator)->GetValue();
    }
    bool containsAce = false;
    for (iterator = m_Cards.begin(); iterator != m_Cards.end(); ++iterator) {
        if ((*iterator)->GetValue() == static_cast<int>(Card::rank::ACE)) {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) {
        total += 10;
    }
    return total;
}

