TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mygol.cpp \
    ../../Desktop/gol_sfml/main.cpp \
    ../../Desktop/gol_sfml/getrect.cpp \
    ../../Desktop/gol_sfml/game.cpp

HEADERS += \
    mygol.h \
    ../../Desktop/gol_sfml/constants.h \
    ../../Desktop/gol_sfml/getrect.h \
    ../../Desktop/gol_sfml/game.h

SUBDIRS += \
    ../../Desktop/gol_sfml/gol_sfml.pro
