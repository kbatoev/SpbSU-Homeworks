QT += core
QT -= gui
QT += testlib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    linkedStack.cpp \
    arrayStack.cpp \
    converterToPostfix.cpp \
    calculator.cpp \
    countPostfix.cpp


HEADERS += \
    stack.h \
    linkedStack.h \
    arrayStack.h \
    converterToPostfix.h \
    calculator.h \
    countPostfix.h \
    arrayStackTest.h \
    linkedStackTest.h \
    counterTest.h \
    postfixConverterTest.h \
    calculatorTest.h
