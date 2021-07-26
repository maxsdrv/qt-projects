#include "Scene.h"
#include "Game.h"

#include <memory>

class Game;

Scene::Scene(QWidget *parent) : QWidget(parent) {
    startButton = new QPushButton(tr("&Start"));
    hitButton = new QPushButton(tr("&Hit"));
    standButton = new QPushButton(tr("&Stand"));
	addButton = new QPushButton(tr("&AddPlayer"));

    connect(startButton, SIGNAL(clicked()), this, SLOT(startBtn()));
    connect(hitButton, SIGNAL(clicked()), this, SLOT(hitBtn()));
    connect(standButton, SIGNAL(clicked()), this, SLOT(standBtn()));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addBtn()));

    auto *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(hitButton);
    buttonLayout->addWidget(standButton);
	buttonLayout->addWidget(addButton);

    buttonLayout->addStretch();

    cardTable = new QListView;
    auto *houseLabel = new QLabel(cardTable);
	auto *playerLabel = new QLabel(cardTable);
    houseLabel->setText("House");
    playerLabel->setText("Player");
    houseLabel->move(10, 20);
    playerLabel->move(10, 150);

    auto *verticalLayout = new QVBoxLayout;
    verticalLayout->addLayout(buttonLayout);
    verticalLayout->addWidget(cardTable);
    hostState = new QLabel("host");
    playerState = new QLabel("player");
    result = new QLabel("result");
    verticalLayout->addWidget(hostState);
    verticalLayout->addWidget(playerState);
    verticalLayout->addWidget(result);

    auto *mainLayout = new QGridLayout;
    mainLayout->addLayout(verticalLayout, 0, 0, 1, 1);

	cardIconHouse.resize(MAXCARDS);
	cardIconPlayers.resize(MAXCARDS);

    setLayout(mainLayout);

    setWindowTitle(tr("BlackJack "));
    resize(1920, 1200);

    setEnableHitStandButtons(false);

    setupIcons();

}

void Scene::setHostStateLabel(QString &s) {
    hostState->setText(s);
}

void Scene::setPlayerStateLabel(QString &s) {
    playerState->setText(s);
}

void Scene::setResultLabel(QString &s) {
    result->setText(s);
}

void Scene::drawCards(GenericPlayer &aGenericPlayer) {
    QPixmap qPixmap;
    std::string str;

    if (typeid(aGenericPlayer) == typeid(Player)) {
         auto *ptr = dynamic_cast<Player *> (&aGenericPlayer);
         auto size = (ptr->getPixmaps()).size();
         for (int i = 0; i < size; ++i) {
             qPixmap = (ptr->getPixmaps())[i];
             cardIconPlayers[i]->setPixmap(qPixmap);
         }
    }
    else if (typeid(aGenericPlayer) == typeid(House)) {
        auto *ptr = dynamic_cast<House *> (&aGenericPlayer);
        auto size = (ptr->getPixmaps()).size();
        for (int i = 0; i < size; ++i) {

        }
    }

}

void Scene::setupIcons() {
    QPixmap qPixmap;
    std::string str;

    for (int i = 0; i < MAXCARDS; ++i) {
		cardIconHouse[i] = new QLabel(cardTable);
		str = ":images/xx.png";
        qPixmap = QPixmap(str.c_str());
		cardIconHouse[i]->setPixmap(qPixmap);
		cardIconHouse[i]->move(100 + 60 * i, 20);

    }

    for (int i = 0; i < MAXCARDS; ++i) {
        cardIconPlayers[i] = new QLabel(cardTable);
		qPixmap = QPixmap(":images/xx.png");
        cardIconPlayers[i]->setPixmap(qPixmap);
        cardIconPlayers[i]->move(100 + 60 * i, 150);
    }
}

void Scene::clearIcons() {
	QPixmap qPixmap = QPixmap(":images/blank.png");
    for (auto& i : cardIconHouse) {
        i->setPixmap(qPixmap);
    }
    for (auto& i : cardIconPlayers) {
        i->setPixmap(qPixmap);
    }
}

void Scene::setEnableHitStandButtons(bool b) {
    hitButton->setEnabled(b);
    standButton->setEnabled(b);
}

void Scene::startBtn() {
    std::vector<std::string> names;
    std::string name = "You";
    names.push_back(name);

	//the game
    myGame = new Game(names, this);

	//initial table setup
	myGame->Play();
	setEnableHitStandButtons(true);

}

void Scene::hitBtn() {
    myGame->hitSelected();
}

void Scene::standBtn() {
    myGame->standSelected();
}

void Scene::addBtn() {

}
