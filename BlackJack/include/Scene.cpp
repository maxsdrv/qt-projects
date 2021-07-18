#include "Scene.h"

#include <memory>


Scene::Scene(QWidget *parent) : QWidget(parent) {
    startButton = new QPushButton(tr("&Start"));
    hitButton = new QPushButton(tr("&Hit"));
    standButton = new QPushButton(tr("&Stand"));

    connect(startButton, SIGNAL(clicked()), this, SLOT(startBtn()));
    connect(hitButton, SIGNAL(clicked()), this, SLOT(hitBtn()));
    connect(standButton, SIGNAL(clicked()), this, SLOT(standBtn()));

    auto *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(hitButton);
    buttonLayout->addWidget(standButton);

    buttonLayout->addStretch();

    cardTable = new QListView;
    auto *houseLabel = new QLabel(cardTable);
    auto playerLabel = new QLabel(cardTable);
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
    setLayout(mainLayout);

    setWindowTitle(tr("BlackJack "));
    resize(1920, 1200);

    setEnableHitStandButtons(false);

    setupIcons();

}

void Scene::setHostStateLabel(QString &s) {

}

void Scene::setPlayerStateLabel(QString &s) {

}

void Scene::setResultLabel(QString &s) {

}

void Scene::drawCards(GenericPlayer &aGenericPlayer) {

}

void Scene::setupIcons() {
    QPixmap qPixmap;
    std::string str;

    for (int i = 0; i < MAXCARDS; ++i) {
        cardIconHouse[i] = new QLabel(cardTable);
        str = "/home/maxim/Cpp/qt-projects/images/blank.png";
        qPixmap = QPixmap(str.c_str());
        cardIconHouse[i]->setPixmap(qPixmap);
        cardIconHouse[i]->move(80 + 60 * i, 20);
    }

    for (int i = 0; i < MAXCARDS; ++i) {
        cardIconPlayers[i] = new QLabel(cardTable);
        qPixmap = QPixmap("/home/maxim/Cpp/qt-projects/images/blank.png");
        cardIconPlayers[i]->setPixmap(qPixmap);
        cardIconPlayers[i]->move(80 + 60 * i, 150);
    }
}

void Scene::clearIcons() {
    QPixmap qPixmap = QPixmap("blank.png");
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

}

void Scene::hitBtn() {

}

void Scene::standBtn() {

}
