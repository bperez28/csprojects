TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    file_record.cpp \
    utilities.cpp

HEADERS += \
    consts.h \
    file_record.h \
    utilities.h
