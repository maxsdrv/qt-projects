QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
		main.cpp \
		include/scene.cpp\
		include/card.cpp\
		include/deck.cpp\
		include/game.cpp\
		include/genericplayer.cpp\
		include/hand.cpp\
		include/house.cpp\
		include/player.cpp

HEADERS += \
				include/scene.h\
		include/card.h\
		include/deck.h\
		include/game.h\
		include/genericplayer.h\
		include/hand.h\
		include/house.h\
		include/player.h


RESOURCES += \
		images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
