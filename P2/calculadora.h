#ifndef CALCULADORA_H
#define CALCULADORA_H
#include "../VO/stack/stack.h"
#include "../common.h"
#include "string.h"
#include <complex>


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
    bool is_complex(const string& s);

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

        char *pch = NULL;
        pch = strtok (expresion, " ");

        while (pch != NULL){
            if (!is_complex(pch) && es_numero(pch)){
                float aux = atof (pch);
                TDATO aux2(aux,0.0);
                pila_.push(aux2);
            }
            else if(es_numero(pch)){
                float p_imag = atof (pch);
                TDATO aux3(0.0,p_imag);
                pila_.push(aux3);
            }
            else{
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

template <class TDATO>
bool calculadora<TDATO>::is_complex(const string& s){
        size_t found = s.find("i");
        return (found != string::npos);
}



}

#endif // calculadora_H
