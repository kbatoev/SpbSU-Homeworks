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
    operatorNode.cpp \
    tree.cpp

HEADERS += \
    treeNode.h \
    operandNode.h \
    operatorNode.h \
    treeTest.h \
    tree.h
