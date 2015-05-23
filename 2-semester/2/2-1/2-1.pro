QT += core

QT -= gui

QT += testlib


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    linkedList.cpp \
    doublyLinkedList.cpp

# include(deployment.pri)
# qtcAddDeployment()

HEADERS += \
    list.h \
    linkedList.h \
    doublyLinkedList.h \
    linkedListTest.h \
    doublyLinkedListTest.h

