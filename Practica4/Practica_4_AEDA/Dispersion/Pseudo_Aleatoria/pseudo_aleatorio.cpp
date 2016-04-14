#include "Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.h"

Pseudo_Aleatorio::Pseudo_Aleatorio()
{}

Pseudo_Aleatorio::~Pseudo_Aleatorio()
{}

unsigned int Pseudo_Aleatorio::dispersion(const DNI& dni, int i) const
{
	srand(dni.get_DNI());
	return rand()%i;
}
