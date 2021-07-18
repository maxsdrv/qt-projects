#include "Player.h"


Player::Player(std::string name) : GenericPlayer(std::move(name)) {}

bool Player::isHitting() const {
    std::cout << m_Name << ". do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const {
    std::cout << m_Name << " wins.\n";
}

void Player::Lose() const {
    std::cout << m_Name << " loses.\n";
}

void Player::Push() const {
    std::cout << m_Name << " pushes.\n";
}


Player::~Player() = default;
