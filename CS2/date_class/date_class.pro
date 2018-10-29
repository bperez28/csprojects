TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    date_class.cpp \
    ../date_library/my_dates_library.cpp

HEADERS += \
    date_class.h \
    ../date_library/my_dates_library.h
