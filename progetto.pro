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
        progetto.cpp\
	helper.cpp \
    application.cpp \
    controllers/controller.cpp \
    application.cpp \
    helper.cpp \
    main.cpp \
    progetto.cpp \
    models/model.cpp \
    views/exampleview.cpp

HEADERS  += progetto.h\
	helper.h \
    application.h \
    controllers/controller.h \
    application.h \
    helper.h \
    progetto.h \
    models/model.h \
    views/exampleview.h

FORMS    += progetto.ui
