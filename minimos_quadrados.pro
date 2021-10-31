TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        GaussSeidel.cpp \
        mmq.cpp

HEADERS += \
    debug.h \
    GaussSeidel.h \
    mmq.h
