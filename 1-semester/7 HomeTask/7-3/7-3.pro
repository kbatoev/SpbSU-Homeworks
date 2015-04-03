TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    hashtable.cpp \
    list.cpp \
    myString.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hashtable.h \
    list.h \
    myString.h

