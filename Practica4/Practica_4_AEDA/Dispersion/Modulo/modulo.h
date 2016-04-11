#ifndef MODULO_H
#define MODULO_H

#include <iomanip>
#include <cmath>
#include "DNI/dni.h"
#include "Celda/celda.h"
#include "Dispersion/dispersion.h"

using namespace std;

class Modulo: public Dispersion
{
	public:
		Modulo();
		~Modulo();

		unsigned int dispersion(const DNI& dni, int n) const;
};

#endif // MODULO_H

/*



*/
