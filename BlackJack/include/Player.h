#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "GenericPlayer.h"
#include "Scene.h"

class Player: public GenericPlayer {
public:
    explicit Player(std::string name = "");
    ~Player() override;

		virtual void makePixmaps(GenericPlayer& aGenericPlayer);

    [[nodiscard]]bool isHitting() const override; //показывает хочет ли игрок брать карты
		void Win(Scene& scene) const; //объявляет что игрок победил
		void Lose(Scene& scene) const; //объявляет что игрок проиграл
		void Push(Scene& scene) const; //объявляет ничью

		static int getHitCount();
		static void resetHitCount();
		static void setHitCount();

		void resultMessage(std::string& s) const;
		std::vector<QPixmap> getPixmaps();
private:
		static int hitCount;
		std::vector<QPixmap> m_pixmaps;
};



#endif //BLACKJACK_PLAYER_H
