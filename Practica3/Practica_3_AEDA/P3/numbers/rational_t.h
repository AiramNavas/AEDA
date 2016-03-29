#ifndef RATIONAL_T
#define RATIONAL_T
#pragma once

#include "common.h"
#include "number_t.h"

class rational_t: public number_t
{
	private:
		float rational_;
	public:
		rational_t();
		rational_t(float rational);
		rational_t(const rational_t& rational);
		~rational_t();

		float get_r() const;

		const entero_t toEntero() const;
		const real_t toReal() const;
		const rational_t toRational() const;
		const complex_t toComplex() const;

		rational_t operator +(const rational_t& r) const;
		rational_t operator -(const rational_t& r) const;
		rational_t operator /(const rational_t& r) const;
		rational_t operator *(const rational_t& r) const;

		virtual ostream& write(ostream& os) const;
};

inline ostream& operator <<(ostream& os, const rational_t& r)
{
	r.write(os);
	return os;
}

#endif // RATIONAL_T

