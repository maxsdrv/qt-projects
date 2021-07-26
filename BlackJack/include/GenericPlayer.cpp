#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(std::string name) : m_Name(std::move(name)) {}

QString GenericPlayer::makeLabelString() {}

void GenericPlayer::makePixmaps(GenericPlayer &aGenericPlayer) {}

bool GenericPlayer::isBusted() const { return (GetTotal() > 21); }

QString GenericPlayer::Bust() const { std::cout << m_Name << " busts.\n"; }

QString &GenericPlayer::getLabelQStr() const {}

std::ostream &operator<<(std::ostream &os, const GenericPlayer &aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";
	std::vector<std::shared_ptr<Card>>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty()) {
		for (pCard = aGenericPlayer.m_Cards.begin();
				 pCard != aGenericPlayer.m_Cards.end(); ++pCard) {
			os << *(*pCard) << "\t";
    }
		if (aGenericPlayer.GetTotal() != 0) {
			std::cout << "(" << aGenericPlayer.GetTotal() << ")";
    }
	} else {
		os << "<empty>";
	}

	return os;
}

GenericPlayer::~GenericPlayer() = default;
