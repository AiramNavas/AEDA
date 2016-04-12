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

		unsigned int exploracion(int i) const;
};

#endif // LINEAL_H
