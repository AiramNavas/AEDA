#include "Exceptions/exceptions.h"
#include "entero_t.h"
#include "real_t.h"
#include "rational_t.h"
#include "complex_t.h"

rational_t::rational_t():
	rational_(0)
{}


rational_t::rational_t(float rational):
	rational_(rational)
{}


rational_t::rational_t(const rational_t& rational):
	rational_(rational.get_r())
{}


rational_t::~rational_t()
{}


float rational_t::get_r() const
{
	return rational_;
}

//	SOBRECARGA DE OPERADOR - RACIONAL CON RACIONAL


rational_t rational_t::operator +(const rational_t& r) const
{
	return (rational_+r.rational_);
}


rational_t rational_t::operator -(const rational_t& r) const
{
	return (rational_-r.rational_);
}


rational_t rational_t::operator /(const rational_t& r) const
{
	if (r.rational_ == 0)
		throw division_zero_exception_t();

	return (rational_/r.rational_);
}


rational_t rational_t::operator *(const rational_t& r) const
{
	return (rational_*r.rational_);
}

//	TO TYPE

const entero_t rational_t::toEntero() const{
	throw invalid_convertion_of_type();
}

const real_t rational_t::toReal() const{
	throw invalid_convertion_of_type();
}

const rational_t rational_t::toRational() const{
	return rational_t(rational_);
}

const complex_t rational_t::toComplex() const{
	return complex_t(rational_,0);
}

//	IMPRECIÓN DE RACIONALES


ostream& rational_t::write(ostream& os) const
{
	os << rational_ << endl;
	return os;
}
