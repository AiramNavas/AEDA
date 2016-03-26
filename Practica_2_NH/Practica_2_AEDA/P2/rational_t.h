#ifndef rational_T
#define rational_T
#pragma once

#include <iostream>
#include <fstream>
using namespace std;

template <class TDATO>
class rational_t
{
private:
    TDATO rational_;
public:
    rational_t();
    rational_t(TDATO rational);
    rational_t(const rational_t& rational);
    ~rational_t();

    TDATO get_r() const;

    rational_t operator +(const rational_t& r) const;
    rational_t operator -(const rational_t& r) const;
    rational_t operator /(const rational_t& r) const;
    rational_t operator *(const rational_t& r) const;

};

template <class TDATO>
rational_t<TDATO>::rational_t():
    rational_(0)
    {}

template <class TDATO>
rational_t<TDATO>::rational_t(TDATO rational):
    rational_(rational)
    {}

template <class TDATO>
rational_t<TDATO>::rational_t(const rational_t& rational):
    rational_(rational.get_r())
    {}

template <class TDATO>
rational_t<TDATO>::~rational_t()
{}

template <class TDATO>
TDATO rational_t<TDATO>::get_r() const
{
    return rational_;
}


template <class TDATO>
rational_t<TDATO> rational_t<TDATO>::operator +(const rational_t& r) const
{
    return (rational_+r.rational_);
}

template <class TDATO>
rational_t<TDATO> rational_t<TDATO>::operator -(const rational_t& r) const
{
    return (rational_-r.rational_);
}

template <class TDATO>
rational_t<TDATO> rational_t<TDATO>::operator /(const rational_t& r) const
{
    return (rational_/r.rational_);
}

template <class TDATO>
rational_t<TDATO> rational_t<TDATO>::operator *(const rational_t& r) const
{
    return (rational_*r.rational_);
}

template <class TDATO>
ostream& operator <<(ostream& os, const rational_t<TDATO>& r)
{
    os << r.get_r() << endl;
    return os;
}


#endif // rational_T

