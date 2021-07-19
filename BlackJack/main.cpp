#include <QApplication>
#include <QPushButton>


#include "include/Card.h"
#include "include/Game.h"
#include "include/Scene.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Scene scene;
    scene.show();




    return QApplication::exec();
}
