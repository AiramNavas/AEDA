#ifndef REAL_T_H
#define REAL_T_H
#pragma once

#include "common.h"
#include "number_t.h"

class real_t: public number_t
{
	private:
		double real_;
	public:
		real_t();
		real_t(double real);
		real_t(const real_t& real);
		~real_t();

		double get_r() const;

		const entero_t toEntero() const;
		const real_t toReal() const;
		const rational_t toRational() const;
		const complex_t toComplex() const;

		number_t* operator +(const number_t* n) const;
		number_t* operator -(const number_t* n) const;
		number_t* operator /(const number_t* n) const;
		number_t* operator *(const number_t* n) const;

		real_t operator +(const real_t& r) const;
		real_t operator -(const real_t& r) const;
		real_t operator /(const real_t& r) const;
		real_t operator *(const real_t& r) const;

		virtual ostream& write(ostream& os) const;
};

inline ostream& operator <<(ostream& os, const real_t& r)
{
	r.write(os);
	return os;
}

#endif // REAL_T_H

