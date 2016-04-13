#ifndef EXPLORACION
#define EXPLORACION

#include <iostream>
#include "DNI/dni.h"

using namespace std;

class Exploracion
{
	public:
		virtual unsigned int exploracion(const DNI& dni, int nCeldas, int i) const=0;
};

#endif // EXPLORACION

