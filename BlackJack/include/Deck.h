#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "GenericPlayer.h"
#include "Hand.h"

#include <QString>

class Deck : public Hand {
public:
	Deck();
	virtual ~Deck();
	void Populate();        //создает колоду из 52 карт
	void Shuffle();         //тасует карты
	void Deal(Hand &aHand); //раздает одну карту в руку
	QString AdditionalCards(
			GenericPlayer &aGenericPlayer); //даёт дополнительные карты игроку
private:
};

#endif // PROJECTPORTFOLIO_DECK_H
