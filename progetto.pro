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

SOURCES += main.cpp\
        progetto.cpp \
    helper.cpp\
    color.cpp \
    wave.cpp \
    audio.cpp \
    coloredwave.cpp

HEADERS  += progetto.h \
    helper.h \
    color.h \
    wave.h \
    audio.h \
    coloredwave.h

FORMS    += progetto.ui
