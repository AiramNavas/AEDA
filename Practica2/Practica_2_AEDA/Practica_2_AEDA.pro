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
    common.h \
    VO/queue/queue.h \
    VO/stack/stack.h \
    VO/vector/vector.h \
    P2/calculadora.h \
    P2/calculadora.h

