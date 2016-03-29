#include "vector.h"

namespace AEDA {

    vector::vector(void):
    base_(NULL),
    n_(0)
    {}

    vector::vector(int n):
    base_(NULL),
    n_(n)
    {
        crea_vector(n_);
    }

    vector::vector(const vector& v):
    base_(NULL),
    n_(v.get_n())
    {
        crea_vector(n_);
        
        for (int i=0;i < n_;i++)
            base_[i] = v[i];
    }

    vector::~vector(void)
    {
        destruye_vector();
    }


    int vector::get_n(void) const
    {
        return n_;
    }
    
    
    void vector::resize(int i)
    {
        destruye_vector();
        n_ = i;
        crea_vector(i);
    }


    TDATO& vector::operator[](int i)
    {
        return base_[i];
    }

    TDATO vector::operator[](int i) const
    {
        return base_[i];
    }

    void vector::crea_vector(int n)
    {
        base_ = new TDATO [n];
    }

    void vector::destruye_vector(void)
    {
        if (base_ != NULL){
            delete [] base_;
            base_ = NULL;
        }
    }


    ostream& vector::write(ostream& os) const
    {
        os << setw(8) << n_ << endl;
        
        for(int i = 0; i < n_; i++)
            os << setw(8) << fixed << setprecision(4) << base_[i] << " ";
            
        os << endl;
            return os;
    }
}