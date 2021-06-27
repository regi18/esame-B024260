cmake_minimum_required(VERSION 3.5)

project(Carletti_Esame_B024260 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH D:\\Software\\Qt\\5.12.11\\mingw73_64)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        views/mainwindow/mainwindow.cpp
        views/mainwindow/mainwindow.h
        views/mainwindow/mainwindow.ui
        interfaces/Subject.h interfaces/Observer.h controllers/ImageUploader.cpp controllers/ImageUploader.h models/ImagesDatabase.cpp models/ImagesDatabase.h models/Image.h)

add_executable(Carletti_Esame_B024260 main.cpp)

add_library(core ${PROJECT_SOURCES})
target_link_libraries(core Qt${QT_VERSION_MAJOR}::Widgets)

add_subdirectory(tests)

target_link_libraries(Carletti_Esame_B024260 core)

set_target_properties(Carletti_Esame_B024260 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
