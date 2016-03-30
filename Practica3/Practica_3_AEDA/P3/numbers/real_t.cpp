#include "Exceptions/exceptions.h"
#include "entero_t.h"
#include "real_t.h"
#include "rational_t.h"
#include "complex_t.h"

real_t::real_t():
	real_(0)
{}


real_t::real_t(double real):
	real_(real)
{}


real_t::real_t(const real_t& real):
	real_(real.get_r())
{}


real_t::~real_t()
{}


double real_t::get_r() const
{
	return real_;
}

//	TO TYPE

const entero_t real_t::toEntero() const{
	throw invalid_convertion_of_type();
}

const real_t real_t::toReal() const{
	return real_t(real_);
}

const rational_t real_t::toRational() const{
	return rational_t(real_);
}

const complex_t real_t::toComplex() const{
	return complex_t(real_,0);
}

//	SOBRECARGA DE OPERADOR - NUMERO CON NUMERO

number_t* real_t::operator +(const number_t* n) const
{
	return  new real_t ((*this)+(n->toReal()));
}
number_t* real_t::operator -(const number_t* n) const
{
	return  new real_t ((*this)-(n->toReal()));
}
number_t* real_t::operator /(const number_t* n) const
{
	return  new real_t ((*this)/(n->toReal()));
}
number_t* real_t::operator *(const number_t* n) const
{
	return  new real_t ((*this)*(n->toReal()));
}

//	SOBRECARGA DE OPERADOR - REAL CON REAL


real_t real_t::operator +(const real_t& r) const
{
	return (real_+r.real_);
}


real_t real_t::operator -(const real_t& r) const
{
	return (real_-r.real_);
}


real_t real_t::operator /(const real_t& r) const
{
	if (r.real_ == 0)
		throw division_zero_exception_t();

	return (real_/r.real_);
}


real_t real_t::operator *(const real_t& r) const
{
	return (real_*r.real_);
}

//	IMPRECIÓN DE RACIONALES


ostream& real_t::write(ostream& os) const
{
	os << real_ << endl;
	return os;
}
