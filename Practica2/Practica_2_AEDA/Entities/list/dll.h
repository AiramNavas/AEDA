#pragma once
#include "common.h"
#include "../node/dll_node.h"

namespace AEDA {

    class dll {
        private:
            dll_node* beginning_;
            dll_node* end_;
        public:
            dll(void);
            ~dll(void);
            
            void insert_beginning(dll_node* n);
            dll_node* extract_beginning(void);
            
            void insert_end(dll_node* n);
            dll_node* extract_end(void);
            
            bool empty(void) const;
            ostream& write(ostream& os) const;
            
            int get_size(void);
            void insert_middle(dll_node* n);
    };
}
