#include <iostream>
#include <thread>
#include "P2/complex_t.h"
#include "P2/calculadora.h"
#include "P2/rational_t.h"
#include "P2/number_t.h"
#include "VO/stack/stack.h"

using namespace std;


int main()
{

    //char expresion[]="3 4i + 1 1i + *";

    AEDA::stack_TDATO<number_t> pila;
    rational_t<int> a(5);
    pila.push(a);

    //number_t *prueba = new rational_t<int>(5);

    cout << pila.pop() << endl;

    return 0;
}

