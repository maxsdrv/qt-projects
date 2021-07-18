#ifndef QT_PROJECTS_SCENE_H
#define QT_PROJECTS_SCENE_H

#include <iostream>
#include <string>
#include <vector>

#include <QtWidgets>
#include <QListView>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QString;
class Player;
class Game;
class GenericPlayer;

const int MAXCARDS = 10;

class Scene : public QWidget {
    Q_OBJECT;
public:
    explicit Scene(QWidget *parent = nullptr);
    void setHostStateLabel(QString &s);
    void setPlayerStateLabel(QString &s);
    void setResultLabel(QString &s);
    void drawCards(GenericPlayer &aGenericPlayer);
    void setupIcons();
    void clearIcons();
    void setEnableHitStandButtons(bool b);
public slots:
    void startBtn();
    void hitBtn();
    void standBtn();
private:
    QPushButton *startButton;
    QPushButton *hitButton;
    QPushButton *standButton;
    QLabel *hostState;
    QLabel *playerState;
    QLabel *result;
    Game *myGame;
    QListView *cardTable;
    QLabel *cardIconHouse[MAXCARDS];
    QLabel *cardIconPlayers[MAXCARDS];
};


#endif //QT_PROJECTS_SCENE_H
