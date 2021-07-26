#include "House.h"

House::House(const std::string &name) : GenericPlayer(name) {
}

bool House::isHitting() const {
    return (GetTotal() <= 16);
}

House::~House() = default;


void House::FlipFirstCard() {
    if (!(m_Cards.empty())) {
        m_Cards[0]->Flip();
    }
}

void House::makePixmaps(GenericPlayer &aGenericPlayer) {
    std::string str;
    std::vector<std::shared_ptr<Card>>::const_iterator pCard;
    if (!m_Cards.empty()) {
        auto *ptr = dynamic_cast<House *> (&aGenericPlayer);
        ptr->pixmaps.clear();
        for (pCard = m_Cards.begin(); pCard != m_Cards.end(); ++pCard) {
            str = (*pCard)->getRank().first;
        }
    }
}

std::vector<QPixmap> &House::getPixmaps() {
    return pixmaps;
}
