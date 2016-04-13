#include "lineal.h"

Lineal::Lineal()
{}

Lineal::~Lineal()
{}

unsigned int Lineal::exploracion(const DNI& dni, int nCeldas, int i) const
{
	return i+1;
}
