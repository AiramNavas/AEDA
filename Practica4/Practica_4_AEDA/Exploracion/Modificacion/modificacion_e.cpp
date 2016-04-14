#include "modificacion_e.h"


Modificacion_E::Modificacion_E()
{}

Modificacion_E::~Modificacion_E()
{}

unsigned int Modificacion_E::exploracion(const DNI& dni, int nCeldas, int i) const
{
	return -i;
}

