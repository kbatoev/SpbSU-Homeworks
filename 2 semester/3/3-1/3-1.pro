TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quickSort.cpp \
    mergeSort.cpp \
    heapSort.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    quickSort.h \
    sorter.h \
    mergeSort.h \
    heapSort.h

