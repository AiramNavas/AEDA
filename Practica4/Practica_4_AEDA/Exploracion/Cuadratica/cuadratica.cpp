#include "cuadratica.h"

Cuadratica::Cuadratica()
{}

Cuadratica::~Cuadratica()
{}

unsigned int Cuadratica::exploracion(const DNI& dni, int nCeldas, int i) const
{
	return i*i;
}
