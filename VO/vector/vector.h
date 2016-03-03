#pragma once
#include "common.h"

namespace AEDA {

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
}