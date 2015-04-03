TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    avl-tree.cpp \
    query.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    avl-tree.h \
    query.h

