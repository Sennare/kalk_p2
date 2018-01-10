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

SOURCES +=  logica/real.cpp \
    logica/complex.cpp \
    logica/quaternion.cpp \
    main.cpp \
    helper.cpp \
    application.cpp \
    controllers/controller.cpp \
    models/model.cpp \
    views/kalkselectorview.cpp \
    controllers/kalkselectorcontroller.cpp \
    views/testview.cpp \
    controllers/testcontroller.cpp \
    views/complexview.cpp \
    controllers/complexcontroller.cpp

HEADERS  += logica/real.h \
    logica/complex.h \
    logica/quaternion.h \
    helper.h \
    application.h \
    controllers/controller.h \
    models/model.h \
    views/kalkselectorview.h \
    controllers/kalkselectorcontroller.h \
    views/testview.h \
    controllers/testcontroller.h \
    views/complexview.h \
    controllers/complexcontroller.h

FORMS    += \
    views/kalkselectorview.ui \
    views/testview.ui \
    views/complexview.ui

RESOURCES += \
    resources.qrc
