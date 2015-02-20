TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    bst.cpp \
    query.cpp

include(deployment.pri)
qtcAddDeployment()

