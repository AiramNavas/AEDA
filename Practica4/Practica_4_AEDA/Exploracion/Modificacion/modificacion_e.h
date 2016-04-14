#ifndef MODIFICACION_E_H
#define MODIFICACION_E_H


#include <iostream>
#include "DNI/dni.h"
#include "Exploracion/exploracion.h"

using namespace std;


class Modificacion_E: public Exploracion
{
	public:
		Modificacion_E();
		~Modificacion_E();

		unsigned int exploracion(const DNI& dni, int nCeldas, int i) const;
};
#endif // MODIFICACION_E_H
