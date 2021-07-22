#ifndef BLACKJACK_GENERICPLAYER_H
#define BLACKJACK_GENERICPLAYER_H

#include <QString>
#include <iostream>
#include <utility>

#include "Hand.h"

class GenericPlayer : public Hand {
public:
	explicit GenericPlayer(std::string name = "");
	virtual ~GenericPlayer();

	QString makeLabelString();
	virtual void makePixmaps(GenericPlayer &aGenericPlayer);

	[[nodiscard]] virtual bool isHitting() const = 0;
	[[nodiscard]] bool
	isBusted() const; //возвращает значение, если игрок имеет перебор
	QString Bust() const; //объявляет что игрок имеет перебор

	QString &getLabelQStr() const;

	friend std::ostream &operator<<(std::ostream &os,
																	const GenericPlayer &aGenericPlayer);

protected:
	std::string m_Name;
	Hand *hand;
	mutable QString labelQstr;
};

#endif // BLACKJACK_GENERICPLAYER_H
