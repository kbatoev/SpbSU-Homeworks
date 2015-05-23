#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T21:17:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 5-1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    hashTable.cpp \
    sumHash.cpp \
    polynomHash.cpp \
    oddFUNction.cpp

HEADERS += \
    hashTable.h \
    list.h \
    hashTableTest.h \
    hashFunction.h \
    hashFunctionTesting.h \
    sumHash.h \
    polynomHash.h \
    oddFUNction.h
