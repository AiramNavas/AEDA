TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DNI/dni.cpp \
    Dispersion/Modulo/modulo.cpp \
    Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.cpp

HEADERS += \
    TablaHash/tablahash.h \
    DNI/dni.h \
    Exceptions/exceptions.h \
    Celda/celda.h \
    Dispersion/dispersion.h \
    Dispersion/Modulo/modulo.h \
    Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.h

