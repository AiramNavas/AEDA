#pragma once
#include "common.h"

namespace AEDA {

    class dll_node {
        private:
            dll_node* next_;
            dll_node* prev_;
        public:
            dll_node(void);
            virtual ~dll_node(void);
            
            void set_next(dll_node* next);
            dll_node* get_next(void) const;
            
            void set_prev(dll_node* prev);
            dll_node* get_prev(void) const;
            
            virtual ostream& write(ostream& os) const = 0;
    };
}