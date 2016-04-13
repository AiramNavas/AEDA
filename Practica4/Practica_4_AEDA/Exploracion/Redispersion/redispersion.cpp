#include "redispersion.h"
#include "Dispersion/dispersion.h"
#include "Dispersion/Modulo/modulo.h"
#include "Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.h"
#include "DNI/dni.h"

Redispersion::Redispersion()
{}

Redispersion::~Redispersion()
{}

unsigned int Redispersion::exploracion(const DNI& dni, int nCeldas, int i) const
{
	Dispersion* dsp;
	if (i%2==0)
		dsp = new Modulo;
	else
		dsp = new Pseudo_Aleatorio;

	return dsp->dispersion(dni,nCeldas)*i;
}
