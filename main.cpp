#include <iostream>
#include "VO/queue/queue.h"
#include "VO/stack/stack.h"
#include "VO/vector/vector.h"
#include "P2/enteros.h"

using namespace std;


template<class TDATO> TDATO calculadora(istream& expresion);


int main()
{

    char expresion[]="2 3 *";

    AEDA::enteros A;

    cout << A.resolver(expresion) << endl;


    return 0;
}

