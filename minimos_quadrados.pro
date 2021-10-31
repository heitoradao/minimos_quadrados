TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GaussSeidel.cpp \
        main.cpp \
        mmq.cpp

HEADERS += \
    GaussSeidel.h \
    debug.h \
    mmq.h
