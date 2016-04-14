#ifndef MODIFICACION_D_H
#define MODIFICACION_D_H


#include <iomanip>
#include <cmath>
#include "DNI/dni.h"
#include "Celda/celda.h"
#include "Dispersion/dispersion.h"

using namespace std;

class Modificacion_D: public Dispersion
{
	public:
		Modificacion_D();
		~Modificacion_D();

		unsigned int dispersion(const DNI& dni, int n) const;
};

#endif // MODIFICACION_D_H
