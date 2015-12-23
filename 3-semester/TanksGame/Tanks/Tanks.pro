#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T17:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    Elements/landscape.cpp \
    Elements/tank.cpp \
    View/gameview.cpp \
    KeyController/keyController.cpp \
    Elements/bullet.cpp \
    Elements/burst.cpp \
    view.cpp

HEADERS  += mainwindow.h \
    game.h \
    Elements/landscape.h \
    Elements/burstable.h \
    Elements/tank.h \
    View/gameview.h \
    KeyController/keyController.h \
    Elements/bullet.h \
    Constants/constants.h \
    Elements/burst.h \
    view.h

FORMS    += mainwindow.ui
