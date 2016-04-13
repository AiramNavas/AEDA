#ifndef LINEAL_H
#define LINEAL_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;


class Lineal: public Exploracion
{
	public:
		Lineal();
		~Lineal();

		unsigned int exploracion(const DNI& dni, int nCeldas, int i) const;
};

#endif // LINEAL_H
