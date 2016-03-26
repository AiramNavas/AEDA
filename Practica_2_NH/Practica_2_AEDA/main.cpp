#include <iostream>
#include <thread>
#include "P2/complex_t.h"
#include "P2/calculadora.h"
#include "P2/rational_t.h"
#include "VO/stack/stack.h"

using namespace std;


int main()
{

    char expresion[]="3 4i + 1 1i + * %";

    string aux =(string)(expresion);
    size_t found = aux.find("i");

    AEDA::calculadora<complex_t<float>> calculadora;

    if (found!=std::string::npos){
        cout << calculadora.resolver(expresion) << endl;
    }
    else
    {
        cout << calculadora.resolver(expresion).real() << endl;
    }


    return 0;
}

