QT += core
QT -= gui

TARGET = Practica_6_AEDA
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    DNI/dni.cpp

HEADERS += \
    ABB/abb.h \
    DNI/dni.h \
    Exceptions/exceptions.h \
    NodoBB/nodobb.h

