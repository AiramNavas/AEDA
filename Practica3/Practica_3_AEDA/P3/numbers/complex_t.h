#ifndef COMPLEX_T_H
#define COMPLEX_T_H
#pragma once

#include "common.h"
#include "number_t.h"

class complex_t: public number_t
{
	private:
		double real_;
		double img_;
	public:
		complex_t();
		complex_t(double real);
		complex_t(double real, double img);
		complex_t(const complex_t& c);
		~complex_t();

		double real() const;
		double img() const;

		const entero_t toEntero() const;
		const real_t toReal() const;
		const rational_t toRational() const;
		const complex_t toComplex() const;

		number_t* operator +(const number_t* n) const;
		number_t* operator -(const number_t* n) const;
		number_t* operator /(const number_t* n) const;
		number_t* operator *(const number_t* n) const;

		complex_t operator+(const complex_t& c) const;
		complex_t operator-(const complex_t& c) const;
		complex_t operator/(const complex_t& c) const;
		complex_t operator*(const complex_t& c) const;
		complex_t operator%(const complex_t& c) const;

		virtual ostream& write(ostream& os) const;
};

inline ostream& operator<<(ostream& os,const complex_t& c)
{
	c.write(os);
	return os;
}

#endif // COMPLEX_T_H
