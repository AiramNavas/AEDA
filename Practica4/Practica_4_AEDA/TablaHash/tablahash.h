#ifndef TABLAHASH
#define TABLAHASH

#include "DNI/dni.h"

template <DNI_type D>
class TablaHash
{
	private:
	public:
		TablaHash(int d);
		~TablaHash();
};

template <DNI_type D>
TablaHash<D>::TablaHash(DNI_type d)
{}

template <DNI_type D>
TablaHash<D>::~TablaHash(){}

#endif // TABLAHASH

