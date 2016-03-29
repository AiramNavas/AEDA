#include "Exceptions/exceptions.h"
#include "entero_t.h"
#include "real_t.h"
#include "rational_t.h"
#include "complex_t.h"


complex_t::complex_t():
	real_(0),
	img_(0)
{}


complex_t::complex_t(double real):
	real_(real),
	img_(0)
{}


complex_t::complex_t(const complex_t& c):
	real_(c.real()),
	img_(c.img())
{}


complex_t::complex_t(double real, double img):
	real_(real),
	img_(img)
{}


complex_t::~complex_t()
{}


double complex_t::real() const
{
	return real_;
}


double complex_t::img() const
{
	return img_;
}

//	SOBRECARGA DE OPERADORES - COMPLEJO CON COMPLEJO


complex_t complex_t::operator +(const complex_t& c) const
{
	return complex_t (real_+c.real_,img_+c.img_);
}


complex_t complex_t::operator -(const complex_t& c) const
{
	return complex_t (real_-c.real_,img_-c.img_);
}


complex_t complex_t::operator /(const complex_t& c) const
{
	double denominador = ((c.real_*c.real_)+(c.img_*c.img_));
	if (denominador == 0)
		throw division_zero_exception_t();

	return complex_t ((((real_*c.real_)+(img_*c.img_))/(denominador)),(((img_*c.real_)-(real_*c.img_))/(denominador)));
}


complex_t complex_t::operator *(const complex_t& c) const
{
	return complex_t (((real_*c.real_)-(img_*c.img_)),((img_*c.real_)+(real_*c.img_)));
}


complex_t complex_t::operator %(const complex_t& c) const
{
	double raiz1 = (c.real_*c.real_+c.img_*c.img_);
	double raiz2 = ((c.real_+sqrt(c.real_*c.real_+c.img_*c.img_))/(2));
	double raiz3 = ((-c.real_+sqrt(c.real_*c.real_+c.img_*c.img_))/(2));

	if (raiz1 < 0 || raiz2 < 0 || raiz3 < 0)
		throw negative_square_root_exception_t();

	if (img_ > 0)
		return complex_t ((sqrt(raiz2)),(+(sqrt(raiz3))));
	else
		return complex_t ((sqrt(raiz2)),(-(sqrt(raiz3))));
}

//	TO TYPE

const entero_t complex_t::toEntero() const{
	throw invalid_convertion_of_type();
}

const real_t complex_t::toReal() const{
	throw invalid_convertion_of_type();
}

const rational_t complex_t::toRational() const{
	throw invalid_convertion_of_type();
}

const complex_t complex_t::toComplex() const{
	return complex_t(real_,img_);
}

// IMPRESIÓN DE COMPLEJO


ostream& complex_t::write(ostream& os) const
{
	if (img_ >= 0)
		os << real_ << "+" << img_ << "i" << endl;
	else
		os << real_ << img_ << "i" << endl;
	return os;
}
