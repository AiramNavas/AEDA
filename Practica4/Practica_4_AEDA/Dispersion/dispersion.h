#ifndef DISPERSION
#define DISPERSION

#include <iostream>
using namespace std;

class Dispersion
{
	public:
		virtual unsigned int dispersion(const DNI& dni, int n) const=0;
};

#endif // DISPERSION
