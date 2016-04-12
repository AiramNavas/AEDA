#ifndef DOBLE_H
#define DOBLE_H

#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;

class Doble: public Exploracion
{
	public:
		Doble();
		~Doble();

		unsigned int exploracion(int i) const;
};

#endif // DOBLE_H
