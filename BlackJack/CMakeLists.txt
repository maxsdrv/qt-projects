cmake_minimum_required(VERSION 3.19)
project(qt_projects)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)
#set(CMAKE_PREFIX_PATH "/home/Qt/6.1.2/gcc_64/lib/cmake") #for linux
set(CMAKE_PREFIX_PATH "D:/Qt/6.1.2/mingw81_64")

set(SOURCE_FILES
        main.cpp
				images.qrc
        include/Card.cpp
        include/Hand.cpp
        include/GenericPlayer.cpp
        include/Player.cpp
        include/House.cpp
        include/Deck.cpp
        include/Game.cpp
        include/Scene.cpp)
set(HEADER_FILES
        include/Hand.h
        include/Card.h
        include/GenericPlayer.h
        include/Player.h
        include/House.h
        include/Deck.h
        include/Game.h
        include/Scene.h)

set(RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/images")

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${RES_FOLDER})

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
