#ifndef BLACKJACK_GENERICPLAYER_H
#define BLACKJACK_GENERICPLAYER_H

#include <iostream>
#include <utility>

#include "Hand.h"

class GenericPlayer: public Hand {
public:
    explicit GenericPlayer(std::string  name = "");
    virtual ~GenericPlayer();
    [[nodiscard]]virtual bool isHitting() const = 0;
    [[nodiscard]]bool isBusted() const; //возвращает значение, если игрок имеет перебор
    void Bust() const; //объявляет что игрок имеет перебор
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
protected:
    std::string m_Name;
};




#endif //BLACKJACK_GENERICPLAYER_H
