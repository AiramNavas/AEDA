#ifndef PSEUDO_ALEATORIO_H
#define PSEUDO_ALEATORIO_H

#include <iostream>
#include <cstdlib>
#include "DNI/dni.h"
#include <random>
#include "Dispersion/dispersion.h"

using namespace std;

class Pseudo_Aleatorio: public Dispersion
{
	public:
		Pseudo_Aleatorio();
		~Pseudo_Aleatorio();

		unsigned int dispersion(const DNI& dni, int n) const;
};

#endif // PSEUDO_ALEATORIO_H

/*


*/
