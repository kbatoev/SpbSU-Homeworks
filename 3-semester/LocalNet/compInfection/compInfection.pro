#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T21:25:29
#
#-------------------------------------------------

QT       += core
QT       += testlib

QT       -= gui

TARGET = compInfection
CONFIG   += console
CONFIG   += c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    isystem.cpp \
    localnet.cpp \
    randomNumberGenerator.cpp \
    statistics.cpp \
    constrandomgenerator.cpp

HEADERS += \
    isystem.h \
    localnet.h \
    wsystem.h \
    lsystem.h \
    msystem.h \
    localnettest.h \
    iNumberGenerator.h \
    randomNumberGenerator.h \
    statistics.h \
    constrandomgenerator.h
