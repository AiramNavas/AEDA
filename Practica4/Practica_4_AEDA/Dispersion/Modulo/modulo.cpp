#include "Dispersion/Modulo/modulo.h"

Modulo::Modulo()
{}


Modulo::~Modulo()
{}


unsigned int Modulo::dispersion(const DNI& dni, int i) const
{
	return dni.get_DNI()%i;
}
