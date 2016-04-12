#ifndef CUADRATICA_H
#define CUADRATICA_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Cuadratica: public Explorasion
{
	public:
		Cuadratica();
		~Cuadratica();

		unsigned int exploracion(const DNI& dni, int n) const;
};

#endif // CUADRATICA_H
