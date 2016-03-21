#ifndef COMPLEX_T_H
#define COMPLEX_T_H
#pragma once

#include <iostream>
#include <fstream>
#include "number_t.h"
using namespace std;

template <class TDATO>
class complex_t: public number_t
{
private:
    TDATO real_;
    TDATO img_;
public:
    complex_t();
    complex_t(TDATO real);
    complex_t(TDATO real, TDATO img);
    complex_t(const complex_t& c);
    ~complex_t();

    TDATO real() const;
    TDATO img() const;

    complex_t operator+(const complex_t& c) const;
    complex_t operator-(const complex_t& c) const;
    complex_t operator/(const complex_t& c) const;
    complex_t operator*(const complex_t& c) const;
};

template <class TDATO>
complex_t<TDATO>::complex_t():
    real_(0),
    img_(0)
{}

template <class TDATO>
complex_t<TDATO>::complex_t(TDATO real):
    real_(real),
    img_(0)
{}

template <class TDATO>
complex_t<TDATO>::complex_t(const complex_t& c):
    real_(c.real()),
    img_(c.img())
{}

template <class TDATO>
complex_t<TDATO>::complex_t(TDATO real, TDATO img):
    real_(real),
    img_(img)
{}

template <class TDATO>
complex_t<TDATO>::~complex_t()
{}

template <class TDATO>
TDATO complex_t<TDATO>::real() const
{
    return real_;
}

template <class TDATO>
TDATO complex_t<TDATO>::img() const
{
    return img_;
}

template <class TDATO>
complex_t<TDATO> complex_t<TDATO>::operator +(const complex_t& c) const
{
    return complex_t<TDATO> (real_+c.real_,img_+c.img_);
}

template <class TDATO>
complex_t<TDATO> complex_t<TDATO>::operator -(const complex_t& c) const
{
    return complex_t<TDATO> (real_-c.real_,img_-c.img_);
}

template <class TDATO>
complex_t<TDATO> complex_t<TDATO>::operator /(const complex_t& c) const
{
    return complex_t<TDATO> ((((real_*c.real_)+(img_*c.img_))/((c.real_*c.real_)+(c.img_*c.img_))),(((img_*c.real_)-(real_*c.img_))/((c.real_*c.real_)+(c.img_*c.img_))));
}

template <class TDATO>
complex_t<TDATO> complex_t<TDATO>::operator *(const complex_t& c) const
{
    return complex_t<TDATO> (((real_*c.real_)-(img_*c.img_)),((img_*c.real_)+(real_*c.img_)));
}

template <class TDATO>
ostream& operator<<(ostream& os,const complex_t<TDATO>& c)
{
    if (c.img() >= 0)
        os << c.real() << "+" << c.img() << "i" << endl;
    else
        os << c.real() << c.img() << "i" << endl;
    return os;
}


#endif // COMPLEX_T_H
