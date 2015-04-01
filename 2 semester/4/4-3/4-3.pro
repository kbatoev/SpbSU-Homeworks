#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T15:27:42
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4-3
TEMPLATE = app


SOURCES += main.cpp\
        calculatorForm.cpp \
    converterToPostfix.cpp \
    countPostfix.cpp \
    linkedStack.cpp \
    calculator.cpp

HEADERS  += calculatorForm.h \
    converterToPostfix.h \
    countPostfix.h \
    linkedStack.h \
    calculator.h

FORMS    += calculatorForm.ui
