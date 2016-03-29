#ifndef NUMBER_T
#define NUMBER_T
#pragma once

#include "common.h"

class entero_t;
class real_t;
class rational_t;
class complex_t;

class number_t {
	public:
		virtual const entero_t toEntero() const = 0;
		virtual const real_t toReal() const = 0;
		virtual const rational_t toRational() const = 0;
		virtual const complex_t toComplex() const = 0;

		virtual ostream& write(ostream& os) const = 0;
};

inline ostream& operator<<(ostream& os, const number_t* n)
{
	n->write(os);
	return os;
}

#endif // NUMBER_T

