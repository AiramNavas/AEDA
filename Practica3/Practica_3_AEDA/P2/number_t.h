#ifndef NUMBER_T
#define NUMBER_T
#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class number_t
{};

ostream& operator <<(ostream& os, const number_t& n)
{
    os << "Soy un numero." << endl;
    return os;
}

#endif // NUMBER_T

