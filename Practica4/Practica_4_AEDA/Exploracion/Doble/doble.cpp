#include "doble.h"

Doble::Doble()
{}

Doble::~Doble()
{}

unsigned int Doble::funcion() const
{
	return 3;
}

unsigned int Doble::exploracion(int i) const
{
	return i*funcion();
}
