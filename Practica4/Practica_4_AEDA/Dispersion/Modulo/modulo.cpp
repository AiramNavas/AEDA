#include "modulo.h"

Modulo::Modulo()
{}


Modulo::~Modulo()
{}


unsigned int Modulo::dispersion(const DNI& dni, int n) const
{
	return dni.get_DNI()%n;
}
