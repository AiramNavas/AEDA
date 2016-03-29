#pragma once
#include "common.h"
#include "dll_node.h"

namespace AEDA {

    class dll_int_node: public dll_node {
        private:
            TDATO c_;
        public:
            dll_int_node(TDATO c);
            virtual ~dll_int_node(void);
            
            virtual ostream& write(ostream& os) const;
            
            TDATO get_data(void);
            void set_data(TDATO c);
    };
}