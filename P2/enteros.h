#ifndef ENTEROS_H
#define ENTEROS_H
#include "../VO/stack/stack.h"
#include "../common.h"
#include "string.h"

namespace AEDA {

// CLASE DE TESTEOS

class enteros
{
private:
    stack_TDATO<TDATO> pila_;

public:
    enteros();
    ~enteros();

    TDATO resolver(char *expresion);
    bool es_numero(char *pch);

};

}

#endif // ENTEROS_H
