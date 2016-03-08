#include <iostream>
#include "VO/queue/queue.h"
#include "VO/stack/stack.h"
#include "VO/vector/vector.h"
#include "P2/calculadora.h"

using namespace std;



int main()
{

    char expresion[]="3 4.5 + 1 + -4i +";

    string aux =(string)(expresion);
    size_t found = aux.find("i");
    if (found!=std::string::npos){

        AEDA::calculadora<complex<float>> A;
        complex<float> B = A.resolver(expresion);
        if (B.imag() > 0)
            cout << "Resultado: " << B.real() << "+" << B.imag() << "i" << endl;
        else
            cout << "Resultado: " << B.real() << B.imag() << "i" << endl;
    }
    else{
        AEDA::calculadora<complex<float>> C;
        complex<float> D = C.resolver(expresion);
        cout << "Resultado: " << D.real() << endl;
    }


    return 0;
}

