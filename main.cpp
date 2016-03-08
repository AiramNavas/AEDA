#include <iostream>
#include "VO/queue/queue.h"
#include "VO/stack/stack.h"
#include "VO/vector/vector.h"
#include "P2/calculadora.h"

using namespace std;



int main()
{
    char expresion[]="5.5 3 * 3 5i + +";

    string aux =(string)(expresion);
    size_t found = aux.find("i");

    AEDA::calculadora<complex<float>> A;
    complex<float> B = A.resolver(expresion);


    if (found!=std::string::npos){
        if (B.imag() > 0)
            cout << "Resultado: " << B.real() << "+" << B.imag() << "i" << endl;
        else
            cout << "Resultado: " << B.real() << B.imag() << "i" << endl;
    }
    else
        cout << "Resultado: " << B.real() << endl;


    return 0;
}

