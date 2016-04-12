TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DNI/dni.cpp \
    Dispersion/Modulo/modulo.cpp \
    Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.cpp \
    Exploracion/Lineal/lineal.cpp \
    Exploracion/Doble/doble.cpp \
    Exploracion/Cuadratica/cuadratica.cpp \
    Exploracion/Redispersion/redispersion.cpp

HEADERS += \
    TablaHash/tablahash.h \
    DNI/dni.h \
    Exceptions/exceptions.h \
    Celda/celda.h \
    Dispersion/dispersion.h \
    Dispersion/Modulo/modulo.h \
    Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.h \
    Exploracion/exploracion.h \
    Exploracion/Lineal/lineal.h \
    Exploracion/Doble/doble.h \
    Exploracion/Cuadratica/cuadratica.h \
    Exploracion/Redispersion/redispersion.h

