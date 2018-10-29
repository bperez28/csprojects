TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    open_hash.h \
    record.h \
    chained_hash.h \
    double_hash.h \
    random.h
