TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bst.cpp \
    bst_functions.cpp \
    tree_node.cpp \
    avl.cpp

HEADERS += \
    bst.h \
    bst_functions.h \
    tree_node.h \
    avl.h
