QT += core
QT -= gui
QT += testlib


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    quickSort.cpp \
    mergeSort.cpp \
    heapSort.cpp

HEADERS += \
    quickSort.h \
    sorter.h \
    mergeSort.h \
    heapSort.h \
    quickSortTest.h \
    mergeSortTest.h \
    heapSortTest.h

