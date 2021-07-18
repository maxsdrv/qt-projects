#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include "Card.h"

class Hand {
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard); //добавляет карту в руку
    [[nodiscard]]int GetTotal() const; //получаем сумму очков карт в руке
protected:
    std::vector<std::shared_ptr<Card>> m_Cards; //используем вектор умных указателей чтобы не думать об освобождении памяти
private:
};


#endif //BLACKJACK_HAND_H
