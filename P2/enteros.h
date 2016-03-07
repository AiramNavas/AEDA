#ifndef CALCULADORA_H
#define CALCULADORA_H
#include "../VO/stack/stack.h"
#include "../common.h"
#include "string.h"


namespace AEDA {

// CLASE DE TESTEOS

template <class TDATO>

class calculadora
{
private:
    stack_TDATO<TDATO> pila_;

public:
    calculadora();
    ~calculadora();

    TDATO resolver(char *expresion);
    bool es_numero(char *pch);

};


template <class TDATO>

calculadora<TDATO>::calculadora():
pila_()
{}
template <class TDATO>

calculadora<TDATO>::~calculadora()
{}

template <class TDATO>
TDATO calculadora<TDATO>::resolver(char *expresion)
{
    // TESTEOS
    char *pch = NULL;
    pch = strtok (expresion, " ");

    while (pch != NULL){
        if (es_numero(pch)){
            TDATO aux = atoi (pch);
            pila_.push(aux);
        }
        else {
            TDATO operador;
            TDATO right = pila_.pop();
            TDATO left = pila_.pop();

            switch (*pch){
                case '+':   operador=(left+right);
                    break;
                case '-':   operador=(left-right);
                    break;
                case '*':   operador=(left*right);
                    break;
                case '/':   operador=(left/right);
                    break;
                case '%':   int a;
                            int b;
                            int c;
                            a =(int)operador;
                            b = (int)left;
                            c = (int)right;
                            a = b%c;
                            operador=(TDATO)a;
                    break;
                default:
                    break;
            }
            pila_.push(operador);
        }
        pch = strtok (NULL, " ");
    }
return pila_.pop();
}
template <class TDATO>

bool calculadora<TDATO>::es_numero(char *pch){
    if (( ((*pch)>='0') && ((*pch)<='9') ) || ( ( (pch[1])>='0') && ((pch[1])<='9') ) )
        return true;
    else
        return false;
}






}

#endif // calculadora_H
