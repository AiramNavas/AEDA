TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DNI/dni.cpp

HEADERS += \
    DNI/dni.h \
    Exceptions/exceptions.h \
    Ordenacion/ordenacion.h \
    Algoritmos_Ord/insercion.h \
    Algoritmos_Ord/burbuja.h \
    Algoritmos_Ord/shellsort.h \
    Algoritmos_Ord/quicksort.h \
    Algoritmos_Ord/mergesort.h \
    Algoritmos_Ord/selectionsort.h \
    Algoritmos_Ord/heap.h

