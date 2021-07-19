#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H


#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Scene.h"

class Game {
public:
    explicit Game(const std::vector<std::string>& names, Scene *scene);
    ~Game();
    void Play();
private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
    Scene *m_scene;
};


#endif //BLACKJACK_GAME_H
