#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H


#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
public:
    Game(const std::vector<std::string>& names);
    ~Game();
    void Play();
private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};


#endif //BLACKJACK_GAME_H
