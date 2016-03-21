#include <iostream>
#include <thread>
#include "P2/complex_t.h"
#include "P2/calculadora.h"
#include "P2/rational_t.h"
#include "P2/number_t.h"
#include "VO/stack/stack.h"

using namespace std;

void func(void *data) {
  // Conversion from MyClass* -> void* is implicit
  rational_t<int> *c = static_cast<rational_t<int>*>(data);
}


int main()
{

    //char expresion[]="3 4i + 1 1i + *";

    AEDA::stack_TDATO<number_t> pila;

    rational_t<int> a(5);
    rational_t<int> b(3);

    pila.push(a);
    pila.push(b);


    rational_t<int> c;
    start_thread(&func, &c).join();


    //rational_t<int> c = (rational_t<int>)pila.pop();
    //rational_t<int> d = pila.pop();

    //cout << c + d << endl;

    return 0;
}

