#ifndef REDISPERSION_H
#define REDISPERSION_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Redispersion: public Exploracion
{
	public:
		Redispersion();
		~Redispersion();

		unsigned int exploracion(const DNI& dni, int nCeldas, int i) const;
};

#endif // REDISPERSION_H
