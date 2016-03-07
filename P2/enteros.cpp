#include "enteros.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

namespace AEDA {

enteros::enteros():
pila_()
{}

enteros::~enteros()
{}

TDATO enteros::resolver(char *expresion)
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

bool enteros::es_numero(char *pch){
    if (( ((*pch)>='0') && ((*pch)<='9') ) || ( ( (pch[1])>='0') && ((pch[1])<='9') ) )
        return true;
    else
        return false;
}

}


