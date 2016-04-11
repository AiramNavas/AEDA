#include "pseudo_aleatorio.h"

Pseudo_Aleatorio::Pseudo_Aleatorio()
{}

Pseudo_Aleatorio::~Pseudo_Aleatorio()
{}

unsigned int Pseudo_Aleatorio::dispersion(const DNI& dni, int n) const
{
	srand(dni.get_DNI());
	return rand()%n;
}
