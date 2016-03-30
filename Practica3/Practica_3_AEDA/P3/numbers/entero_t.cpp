#include "Exceptions/exceptions.h"
#include "entero_t.h"
#include "real_t.h"
#include "rational_t.h"
#include "complex_t.h"

entero_t::entero_t():
	entero_(0)
{}


entero_t::entero_t(int entero):
	entero_(entero)
{}


entero_t::entero_t(const entero_t& entero):
	entero_(entero.get_e())
{}


entero_t::~entero_t()
{}


int entero_t::get_e() const
{
	return entero_;
}

//	TO TYPE

const entero_t entero_t::toEntero() const{
	return entero_t(entero_);
}

const real_t entero_t::toReal() const{
	return real_t(entero_);
}

const rational_t entero_t::toRational() const{
	return rational_t(entero_);
}

const complex_t entero_t::toComplex() const{
	return complex_t(entero_,0);
}

//	SOBRECARGA DE OPERADOR - NUMERO CON NUMERO

number_t* entero_t::operator +(const number_t* n) const
{
	return  new entero_t ((*this)+(n->toEntero()));
}
number_t* entero_t::operator -(const number_t* n) const
{
	return  new entero_t ((*this)-(n->toEntero()));
}
number_t* entero_t::operator /(const number_t* n) const
{
	return  new entero_t ((*this)/(n->toEntero()));
}
number_t* entero_t::operator *(const number_t* n) const
{
	return  new entero_t ((*this)*(n->toEntero()));
}

//	SOBRECARGA DE OPERADOR - ENTERO CON ENTERO


entero_t entero_t::operator +(const entero_t& e) const
{
	return (entero_+e.entero_);
}


entero_t entero_t::operator -(const entero_t& e) const
{
	return (entero_-e.entero_);
}


entero_t entero_t::operator /(const entero_t& e) const
{
	if (e.entero_ == 0)
		throw division_zero_exception_t();

	return (entero_/e.entero_);
}


entero_t entero_t::operator *(const entero_t& e) const
{
	return (entero_*e.entero_);
}

//	IMPRECIÓN DE RACIONALES


ostream& entero_t::write(ostream& os) const
{
	os << entero_ << endl;
	return os;
}
