#include "Player.h"


Player::Player(std::string name) : GenericPlayer(std::move(name)) {}

void Player::makePixmaps(GenericPlayer &aGenericPlayer)
{

}

bool Player::isHitting() const {
    std::cout << m_Name << ". do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win(Scene& scene) const {
    std::cout << m_Name << " wins.\n";
}

void Player::Lose(Scene& scene) const {
    std::cout << m_Name << " loses.\n";
}

void Player::Push(Scene& scene) const {
	std::cout << m_Name << " pushes.\n";
}

void Player::resultMessage(std::string &s) const
{

}

std::vector<QPixmap> Player::getPixmaps()
{

}


Player::~Player() = default;
