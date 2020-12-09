TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += /std:c++17

SOURCES += \
        main.cpp

DISTFILES += \
    input11.txt \
    input13.txt \
    input18.txt \
    p022_names.txt \
    p042_words.txt

HEADERS += \
    division.h \
    functions.h
