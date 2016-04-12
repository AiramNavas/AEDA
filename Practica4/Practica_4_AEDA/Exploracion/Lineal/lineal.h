#ifndef LINEAL_H
#define LINEAL_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;


class Lineal: public Explorasion
{
	public:
		Lineal();
		~Lineal();

		unsigned int exploracion(const DNI& dni, int n) const;
};

#endif // LINEAL_H
