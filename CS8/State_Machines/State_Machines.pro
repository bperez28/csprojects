TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    token.cpp \
    stokenizer.cpp \
    table_functions.cpp \
    ftokenizer.cpp

HEADERS += \
    token.h \
    stokenizer.h \
    table_functions.h \
    ftokenizer.h

DISTFILES += \
    ../../Downloads/solitude.txt \
    solitude.txt
