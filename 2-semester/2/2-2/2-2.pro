TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    linkedStack.cpp \
    arrayStack.cpp \
    converterToPostfix.cpp \
    calculator.cpp \
    countPostfix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    linkedStack.h \
    arrayStack.h \
    converterToPostfix.h \
    calculator.h \
    countPostfix.h

