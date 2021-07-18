#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "GenericPlayer.h"

class Player: public GenericPlayer {
public:
    explicit Player(std::string name = "");
    ~Player() override;

    [[nodiscard]]bool isHitting() const override; //показывает хочет ли игрок брать карты
    void Win() const; //объявляет что игрок победил
    void Lose() const; //объявляет что игрок проиграл
    void Push() const; //объявляет ничью
private:
};



#endif //BLACKJACK_PLAYER_H
