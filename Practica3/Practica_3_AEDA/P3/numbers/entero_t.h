#ifndef ENTERO_T_H
#define ENTERO_T_H
#pragma once

#include "common.h"
#include "number_t.h"

class entero_t: public number_t
{
	private:
		int entero_;
	public:
		entero_t();
		entero_t(int entero);
		entero_t(const entero_t& entero);
		~entero_t();

		int get_e() const;

		const entero_t toEntero() const;
		const real_t toReal() const;
		const rational_t toRational() const;
		const complex_t toComplex() const;

		number_t* operator +(const number_t* n) const;
		number_t* operator -(const number_t* n) const;
		number_t* operator /(const number_t* n) const;
		number_t* operator *(const number_t* n) const;

		entero_t operator +(const entero_t& e) const;
		entero_t operator -(const entero_t& e) const;
		entero_t operator /(const entero_t& e) const;
		entero_t operator *(const entero_t& e) const;

		virtual ostream& write(ostream& os) const;
};

inline ostream& operator <<(ostream& os, const entero_t& e)
{
	e.write(os);
	return os;
}

#endif // ENTERO_T_H

