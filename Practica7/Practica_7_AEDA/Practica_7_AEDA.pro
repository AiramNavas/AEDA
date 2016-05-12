QT += core
QT -= gui

TARGET = Practica_7_AEDA
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    DNI/dni.cpp

HEADERS += \
    DNI/dni.h \
    Exceptions/exceptions.h \
    NodoAVL/nodoavl.h \
    ArbolAVL/arbolavl.h

