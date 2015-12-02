#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T17:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    landscape.cpp \
    tank.cpp \
    updater.cpp \
    gameview.cpp

HEADERS  += mainwindow.h \
    game.h \
    landscape.h \
    burstable.h \
    tank.h \
    updater.h \
    gameview.h

FORMS    += mainwindow.ui
