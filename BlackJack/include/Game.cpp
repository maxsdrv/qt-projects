#include "Game.h"
#include <random>


Game::Game(const std::vector<std::string> &names) {
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName) {
        m_Players.emplace_back(Player(*pName));
    }
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game() {
}

void Game::Play() {
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard();
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        m_Deck.AdditionalCards(*pPlayer);
    }
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;

    m_Deck.AdditionalCards(m_House);
    if (m_House.isBusted()) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!(pPlayer->isBusted())) {
                pPlayer->Win();
            }
        }
    }
    else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!(pPlayer->isBusted())) {
                if (pPlayer->GetTotal() > m_House.GetTotal()) {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal()) {
                    pPlayer->Lose();
                }
                else {
                    pPlayer->Push();
                }
            }
        }
    }
    m_Players.clear();

}





