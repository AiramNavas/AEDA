#pragma once
#include "common.h"
#include "Exceptions/exceptions.h"

namespace AEDA {

    template <class TDATO>
    class vector{
        private:
            TDATO*  base_;
            int     n_;
        public:
            vector(void);
            vector(int n);
            vector(const vector& v);
            virtual ~vector(void);

            int get_n(void) const;

            void resize(int n);

            TDATO& operator[](int i);
            TDATO operator[](int i) const;

            ostream& write(ostream& os) const;
        private:
            void crea_vector(int n);
            void destruye_vector(void);
    };


    template <class TDATO>
    vector<TDATO>::vector(void):
    base_(NULL),
    n_(0)
    {}

    template <class TDATO>
    vector<TDATO>::vector(int n):
    base_(NULL),
    n_(n)
    {
        try {
            crea_vector(n_);
        }
        catch (bad_size_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }

        catch (out_of_mem_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }
    }

    template <class TDATO>
    vector<TDATO>::vector(const vector& v):
    base_(NULL),
    n_(v.get_n())
    {
        try {
            crea_vector(n_);
            for (int i=0;i < n_;i++)
                base_[i] = v[i];
        }

        catch (bad_size_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }

        catch (out_of_mem_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }
    }

    template <class TDATO>
    vector<TDATO>::~vector(void)
    {
        destruye_vector();
    }

    template <class TDATO>
    int vector<TDATO>::get_n(void) const
    {
        return n_;
    }

    template <class TDATO>
    void vector<TDATO>::resize(int i)
    {
        destruye_vector();
        n_ = i;

        try {
            crea_vector(n_);
        }
        catch (bad_size_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }

        catch (out_of_mem_exception_t& e){
            n_ = 0;
            cout << e.what() << endl;
        }
    }

    template <class TDATO>
    TDATO& vector<TDATO>::operator[](int i)
    {
        if(i < 0)
            throw low_index_exception_t();
		if(i >= n_)
            throw high_index_exception_t();

        return base_[i];
    }

    template <class TDATO>
    TDATO vector<TDATO>::operator[](int i) const
    {
        if(i < 0)
            throw low_index_exception_t();
		if(i >= n_)
            throw high_index_exception_t();

        return base_[i];
    }

    template <class TDATO>
    void vector<TDATO>::crea_vector(int n)
    {
        if(n_ <= 0)
            throw bad_size_exception_t();

        base_ = new TDATO [n];

        if(base_ == NULL)
            throw out_of_mem_exception_t();
    }

    template <class TDATO>
    void vector<TDATO>::destruye_vector(void)
    {
        if (base_ != NULL){
            delete [] base_;
            base_ = NULL;
        }
    }

    template <class TDATO>
    ostream& vector<TDATO>::write(ostream& os) const
    {
        if(n_ <= 0)
            throw writing_empty_exception_t();

        os << setw(8) << n_ << endl;

        for(int i = 0; i < n_; i++)
            os << setw(8) << fixed << setprecision(4) << base_[i] << " ";

        os << endl;
            return os;
    }


}
