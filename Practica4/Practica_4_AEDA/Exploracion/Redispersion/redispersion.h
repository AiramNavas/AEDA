#ifndef REDISPERSION_H
#define REDISPERSION_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Redispersion: public Explorasion
{
	public:
		Redispersion();
		~Redispersion();

		unsigned int exploracion(const DNI& dni, int n) const;
};

#endif // REDISPERSION_H
