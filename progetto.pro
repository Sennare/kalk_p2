#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T15:53:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = progetto
TEMPLATE = app

# Uncomment to enable C++11 support
CONFIG += c++11

SOURCES += main.cpp\
        progetto.cpp\
	  helper.cpp \
    application.cpp \
    models/model.cpp \
    exce_kalk.cpp\
    views/kalkselectorview.cpp \
    views/testview.cpp \
    logica/color.cpp \
    logica/wave.cpp \
    logica/audio.cpp \
    logica/coloredwave.cpp \
    views/audioview.cpp \
    views/utils/qcustomplot.cpp \
    views/coloredwaveview.cpp \
    views/view.cpp

HEADERS  += progetto.h\
	helper.h \
    application.h \
    models/model.h \
    exce_kalk.h\
    views/kalkselectorview.h \
    views/testview.h \
    logica/color.h \
    logica/wave.h \
    logica/audio.h \
    logica/coloredwave.h \
    views/audioview.h \
    views/utils/qcustomplot.h \
    views/coloredwaveview.h \
    views/view.h

FORMS    += progetto.ui \
    views/kalkselectorview.ui \
    views/testview.ui \
    views/audioview.ui \
    views/coloredwaveview.ui

RESOURCES += \
    resources.qrc
