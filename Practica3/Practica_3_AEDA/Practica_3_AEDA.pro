TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Entities/list/dll.cpp \
    Entities/node/dll_node.cpp

HEADERS += \
    Entities/list/dll.h \
    Entities/node/dll_int_node.h \
    Entities/node/dll_node.h \
    P2/calculadora.h \
    VO/queue/queue.h \
    VO/stack/stack.h \
    VO/vector/vector.h \
    common.h \
    P2/complex_t.h \
    P2/rational_t.h \
    P2/number_t.h

