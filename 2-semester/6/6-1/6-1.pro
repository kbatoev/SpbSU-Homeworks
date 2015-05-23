#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T14:45:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 6-1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    operandNode.cpp \
    tree.cpp \
    addition.cpp \
    multiplication.cpp \
    subtraction.cpp \
    division.cpp

HEADERS += \
    treeNode.h \
    operandNode.h \
    treeTest.h \
    tree.h \
    addition.h \
    multiplication.h \
    subtraction.h \
    division.h
