#ifndef BLACKJACK_HOUSE_H
#define BLACKJACK_HOUSE_H

#include "GenericPlayer.h"

class House: public GenericPlayer {
public:
    explicit House(const std::string& name = "House");
    virtual ~House();
    [[nodiscard]] bool isHitting()  const override; //показывает хочет ли игрок продолжать брать карты
    void FlipFirstCard(); //переворачивает первую карту
private:
};


#endif //BLACKJACK_HOUSE_H
