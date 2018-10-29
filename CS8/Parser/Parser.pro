TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../State_Machines/ftokenizer.cpp \
    ../State_Machines/stokenizer.cpp \
    ../State_Machines/table_functions.cpp \
    ../State_Machines/token.cpp \
    ../binary_file_fun/file_record.cpp \
    ../binary_file_fun/utilities.cpp

HEADERS += \
    ../BTrees/array_functions.h \
    ../BTrees/bplustree.h \
    ../BTrees/btree.h \
    ../BTrees/map.h \
    ../BTrees/mmap.h \
    ../BTrees/mpair.h \
    ../BTrees/pair.h \
    parse.h \
    table.h \
    ../State_Machines/ftokenizer.h \
    ../State_Machines/stokenizer.h \
    ../State_Machines/table_functions.h \
    ../State_Machines/token.h \
    ../binary_file_fun/consts.h \
    ../binary_file_fun/file_record.h \
    ../binary_file_fun/utilities.h \
    sql.h

SUBDIRS += \
    ../BTrees/BTrees.pro \
    ../BTrees/BTrees.pro \
    ../State_Machines/State_Machines.pro \
    ../binary_file_fun/binary_file_fun.pro \
    ../binary_file_fun/binary_file_fun.pro

DISTFILES += \
    (Bryans-MacBook-Pro.local's conflicted copy 2018-05-28).user \
    ../State_Machines/State_Machines.pro.user \
    (Bryans-MacBook-Pro.local's conflicted copy 2018-05-28).user \
    ../State_Machines/_FTokenizer.rtf \
    ../State_Machines/solitude.txt \
    ../binary_file_fun/_!batch_file.batch
