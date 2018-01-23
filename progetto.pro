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
          helper.cpp \
    application.cpp \
    models/model.cpp \
    exce_kalk.cpp \
    logica/real.cpp \
    logica/complex.cpp \
    logica/quaternion.cpp \
    logica/color.cpp \
    logica/wave.cpp \
    logica/audio.cpp \
    logica/coloredwave.cpp \
    views/complexview.cpp \
    views/quaternionview.cpp \
    views/kalkselectorview.cpp \
    views/testview.cpp \
    views/audioview.cpp \
    views/utils/qcustomplot.cpp \
    views/coloredwaveview.cpp \
    views/view.cpp \
    views/utils/tastierinoview.cpp

HEADERS  += helper.h \
    application.h \
    models/model.h \
    exce_kalk.h \
    logica/real.h \
    logica/complex.h \
    logica/quaternion.h \
    logica/color.h \
    logica/wave.h \
    logica/audio.h \
    logica/coloredwave.h \
    views/complexview.h \
    views/quaternionview.h \
    views/kalkselectorview.h \
    views/testview.h \
    views/audioview.h \
    views/utils/qcustomplot.h \
    views/coloredwaveview.h \
    views/view.h \
    views/utils/tastierinoview.h

FORMS    += views/kalkselectorview.ui \
    views/testview.ui \
    views/audioview.ui \
    views/coloredwaveview.ui \
    views/complexview.ui \
    views/utils/tastierinoview.ui

RESOURCES += \
    resources.qrc
