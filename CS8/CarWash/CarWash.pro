TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    averager.cpp \
    probability.cpp

HEADERS += \
    averager.h \
    probability.h
