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
	void addBtn();
private:
    QPushButton *startButton;
    QPushButton *hitButton;
    QPushButton *standButton;
	QPushButton *addButton;
    QLabel *hostState;
    QLabel *playerState;
    QLabel *result;
    Game *myGame;
    QListView *cardTable;
	std::vector<QLabel*> cardIconHouse;
	std::vector<QLabel*> cardIconPlayers;
	static inline const int MAXCARDS = 10;
};


#endif //QT_PROJECTS_SCENE_H
