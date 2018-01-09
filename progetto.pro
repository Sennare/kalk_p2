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
    models/model.cpp \
    views/exampleview.cpp \
    controllers/kalkselectorcontroller.cpp \
    views/kalkselectorview.cpp

HEADERS  += progetto.h\
	helper.h \
    application.h \
    controllers/controller.h \
    models/model.h \
    views/exampleview.h \
    controllers/kalkselectorcontroller.h \
    views/kalkselectorview.h

FORMS    += progetto.ui \
    views/kalkselectorview.ui
