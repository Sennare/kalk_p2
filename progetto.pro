#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T15:53:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progetto
TEMPLATE = app

# Uncomment to enable C++11 support
CONFIG += c++11

SOURCES +=  real.cpp \
    complex.cpp \
    main.cpp\
    progetto.cpp \
    quaternion.cpp \
    numberscalculator.cpp

HEADERS  += real.h \
    progetto.h \
    complex.h \
    quaternion.h \
    numberscalculator.h

FORMS    += progetto.ui \
    numberscalculator.ui
