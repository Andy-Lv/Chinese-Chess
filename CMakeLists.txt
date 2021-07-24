cmake_minimum_required(VERSION 3.19)
project(ChineseChess)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(SRCS_FILES
        src/main.cpp
        src/SelectGameMode.cpp
        src/ChooseMainWindow.cpp
        src/MachineGame.cpp
        src/NetworkGame.cpp
        src/ChessBoard.cpp
        form/ui_AboutAuthor.cpp
        form/ui_ChessBoard.cpp include/ChessPieces.h src/ChessPieces.cpp include/AboutAuthor.h src/AboutAuthor.cpp include/ChessStep.h src/ChessStep.cpp)

# 需要配置环境变量QT5_DIR
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT5_DIR})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Svg REQUIRED)
if (Qt5Core_FOUND AND Qt5Widgets_FOUND AND Qt5Gui_FOUND AND
        Qt5OpenGL_FOUND AND Qt5Network_FOUND AND Qt5Xml_FOUND AND Qt5Svg_FOUND)
    set(QT_INCLUDES ${QT_INCLUDES}
            ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS}
            ${Qt5Network_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS} ${Qt5Svg_INCLUDE_DIRS})
    include_directories(${QT_INCLUDES})
endif()

qt5_wrap_cpp(MOC_SRCS NetworkGame.h
        ../include/SelectGameMode.h
        ../include/ChooseMainWindow.h
        ../include/ChessStep.h
        ../include/ChessBoard.h
        ../include/AboutAuthor.h
        ../form/ui_AboutAuthor.h
        ../form/ui_ChessBoard.h)
qt5_wrap_ui(UI_HEADERS
        form/AboutAuthor.ui
        form/ChessBoard.ui)
qt5_add_resources(QRCS chooseresource.qrc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(images)
include_directories(include)
include_directories(src)
include_directories(form)

# 指定生成目标
add_executable(${PROJECT_NAME}
        ${SRCS_FILES}
        ${UI_HEADERS}
        ${MOC_SRCS}
        ${QRCS})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        )
