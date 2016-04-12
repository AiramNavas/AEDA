#ifndef DOBLE_H
#define DOBLE_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Doble: public Explorasion
{
	public:
		Doble();
		~Doble();

		unsigned int exploracion(const DNI& dni, int n) const;
};

#endif // DOBLE_H
