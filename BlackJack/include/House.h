#ifndef BLACKJACK_HOUSE_H
#define BLACKJACK_HOUSE_H

#include <QPixmap>

#include "GenericPlayer.h"

class House: public GenericPlayer {
public:
    explicit House(const std::string& name = "House");
    virtual ~House();
    [[nodiscard]] bool isHitting()  const override; //показывает хочет ли игрок продолжать брать карты
    void FlipFirstCard(); //переворачивает первую карту

    void makePixmaps(GenericPlayer& aGenericPlayer) override;

    std::vector<QPixmap>& getPixmaps();
private:
    std::vector<QPixmap> pixmaps;
};


#endif //BLACKJACK_HOUSE_H
