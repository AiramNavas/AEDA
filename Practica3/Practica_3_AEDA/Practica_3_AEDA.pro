TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Entities/list/dll.cpp \
    Entities/node/dll_node.cpp \
    P3/numbers/complex_t.cpp \
    P3/numbers/entero_t.cpp \
    P3/numbers/rational_t.cpp \
    P3/numbers/real_t.cpp \
    P3/number_list/number_list.cpp \
    P3/calculadora_numeros/calculadora_numeros.cpp

HEADERS += \
    Entities/list/dll.h \
    Entities/node/dll_int_node.h \
    Entities/node/dll_node.h \
    VO/queue/queue.h \
    VO/stack/stack.h \
    VO/vector/vector.h \
    common.h \
    Exceptions/exceptions.h \
    P3/numbers/complex_t.h \
    P3/numbers/entero_t.h \
    P3/numbers/number_t.h \
    P3/numbers/rational_t.h \
    P3/numbers/real_t.h \
    P3/number_list/number_list.h \
    P3/calculadora_numeros/calculadora_numeros.h
